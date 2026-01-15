#include <stdio.h>

int main()
{
    int frames[50], f, i;
    int retry, max_retry = 3;

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter %d frames (-1 for error):\n", f);
    for (i = 1; i <= f; i++)
        scanf("%d", &frames[i]);

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
            printf("Transmission failed for frame %d\n", i);
            break;
        }
    }

    return 0;
}

