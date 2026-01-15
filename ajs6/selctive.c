#include <stdio.h>

int main()
{
    int frames[50], ack[50] = {0};
    int f, w, i, completed = 0;

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter window size: ");
    scanf("%d", &w);

    printf("Enter %d frames (-1 for error):\n", f);
    for (i = 1; i <= f; i++)
        scanf("%d", &frames[i]);

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
                    printf("Error: Frame %d not sent, will retransmit later\n\n", i);
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

    return 0;
}

