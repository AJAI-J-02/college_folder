#include <stdio.h>

int main()
{
    int frames[50], retry[50] = {0};
    int f, w, i;
    int max_retry = 3;

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter window size: ");
    scanf("%d", &w);

    printf("Enter %d frames (-1 for error):\n", f);
    for (i = 1; i <= f; i++)
        scanf("%d", &frames[i]);

    printf("\n--- SLIDING WINDOW (GO-BACK-N) PROTOCOL ---\n\n");

    for (i = 1; i <= f; i++)
    {
        printf("Sending frame %d\n", i);

        if (frames[i] == -1)
        {
            retry[i]++;

            if (retry[i] > max_retry)
            {
                printf("Frame %d dropped after %d retries\n\n", i, max_retry);
                continue;
            }

            printf("Error: Frame %d not sent\n", i);
            printf("Go-Back-N: Retransmitting from frame %d (Retry %d/%d)\n\n",
                   i, retry[i], max_retry);
            i--;   
            continue;
        }

        if (i % w == 0)
        {
            printf("Acknowledgement received for last %d frames\n\n", w);
        }
    }

    if (f % w != 0)
        printf("Acknowledgement received for remaining frames\n");

    return 0;
}

