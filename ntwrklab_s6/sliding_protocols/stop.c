#include <stdio.h>

int main()
{
    int frames[50], f, i;
    int retry;
    printf("Enter number of frames: ");
    scanf("%d", &f);
    printf("Enter %d frames (-1 for error):\n", f);
    for (i = 0; i < f; i++)
        scanf("%d", &frames[i]);
    printf("\n--- STOP AND WAIT PROTOCOL ---\n\n");
    for (i = 0; i < f; i++)
    {
        retry = 0;
        while (1)
        {
            printf("Sending frame %d...\n", i + 1);
            if (frames[i] == -1)
            {
                retry++;
                printf("Error: Frame %d lost! Retry %d\n\n",
                       i + 1, retry);
                frames[i] = (i + 1) * 10;
            }
            else
            {
                printf("Frame %d received successfully\n", frames[i]);
                printf("Acknowledgement received\n\n");
                break;
            }
        }
    }
    return 0;
}

