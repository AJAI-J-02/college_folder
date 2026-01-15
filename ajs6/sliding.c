#include <stdio.h>

int main()
{
    int frames[50], f, w, i;

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
            printf("Error: Frame %d not sent\n", i);
            printf("Go-Back-N: Retransmitting from frame %d\n\n", i);
            i--;  
            continue;
        }

        if (i % w == 0)
        {
            printf("Acknowledgement received for last %d frames\n\n", w);
        }
    }

    if (f % w != 0)
        printf("\nAcknowledgement received for remaining frames\n");

    return 0;
}

