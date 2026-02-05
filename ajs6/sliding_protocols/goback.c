#include <stdio.h>

int main()
{
    int frames[50], retry[50] = {0};
    int f, w, i;

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter window size: ");
    scanf("%d", &w);

    printf("Enter %d frames (-1 for error):\n", f);
    for (i = 1; i <= f; i++)
        scanf("%d", &frames[i]);

    printf("\n--- GO-BACK-N PROTOCOL ---\n\n");

    for (i = 1; i <= f; i++)
    {
        while (frames[i] == -1)
        {
            retry[i]++;
            printf("Sending frame %d...\n", i);
            printf("Frame %d lost! Retry %d\n\n", i, retry[i]);

            if (retry[i] >= 1)
            {
                frames[i] = i * 10;
            }
        }

        printf("Sending frame %d...\n", i);
        printf("Frame %d received successfully\n", frames[i]);
        printf("Acknowledgement sent for frame %d\n\n", i);

        if (i % w == 0)
            printf("Window acknowledgement received for last %d frames\n\n", w);
    }

    if (f % w != 0)
        printf("Window acknowledgement received for remaining frames\n");

    return 0;
}
