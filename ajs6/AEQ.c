#include <stdio.h>

void stop_and_wait(int frames[], int f)
{
    int i;
    int retry, max_retry = 3;

    printf("\n--- STOP AND WAIT PROTOCOL ---\n\n");

    for (i = 1; i <= f; i++)
    {
        retry = 0;

        while (retry < max_retry)
        {
            printf("Sending frame %d...\n", i);

            if (frames[i] == -1)
            {
                retry++;
                printf("Error: Frame %d not sent! Retry %d/%d\n\n",
                       i, retry, max_retry);
            }
            else
            {
                printf("Frame %d received successfully\n", frames[i]);
                printf("Acknowledgement received\n\n");
                break;
            }
        }

        if (retry == max_retry)
        {
            printf("Transmission failed for frame %d after %d retries\n\n",
                   i, max_retry);
            return; 
        }
    }
}

void sliding_window(int frames[], int f, int w)
{
    int i;
    printf("\n--- SLIDING WINDOW (GO-BACK-N) PROTOCOL ---\n\n");

    for (i = 1; i <= f; i++)
    {
        printf("Sending frame %d\n", i);

        if (frames[i] == -1)
        {
            printf("Error: Frame %d not sent!\n", i);
            printf("Go-Back-N: Retransmitting from frame %d\n\n", i);
            i--; 
            continue;
        }

        if (i % w == 0)
        {
            printf("Acknowledgement received for frames %d to %d\n\n", i - w + 1, i);
        }
    }

    if (f % w != 0)
    {
        printf("Acknowledgement received for remaining frames\n\n");
    }
}

void selective_repeat(int frames[], int f, int w)
{
    int ack[50] = {0};
    int i, completed = 0;

    printf("\n--- SELECTIVE REPEAT PROTOCOL ---\n\n");

    while (completed < f)
    {
        for (i = 1; i <= f; i++)
        {
            if (ack[i] == 0)
            {
                printf("Sending frame %d...\n", i);

                if (frames[i] == -1)
                {
                    printf("Error: Frame %d not sent! Will retransmit later\n\n", i);
                }
                else
                {
                    printf("Frame %d received successfully\n", frames[i]);
                    printf("Acknowledgement received for frame %d\n\n", i);
                    ack[i] = 1;
                    completed++;
                }
            }
        }
    }
}

int main()
{
    int w, f, i, choice;
    int frames[50];

    printf("Enter number of frames to transmit: ");
    scanf("%d", &f);

    printf("Enter %d frames (use -1 to simulate frame not sent):\n", f);
    for (i = 1; i <= f; i++)
        scanf("%d", &frames[i]);

    printf("\nChoose Protocol:\n");
    printf("1. Stop and Wait\n");
    printf("2. Sliding Window (Go-Back-N)\n");
    printf("3. Selective Repeat\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 2 || choice == 3)
    {
        printf("Enter window size: ");
        scanf("%d", &w);
    }

    switch (choice)
    {
    case 1:
        stop_and_wait(frames, f);
        break;
    case 2:
        sliding_window(frames, f, w);
        break;
    case 3:
        selective_repeat(frames, f, w);
        break;
    default:
        printf("Invalid choice\n");
    }

    return 0;
}

