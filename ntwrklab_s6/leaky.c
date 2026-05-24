#include <stdio.h>

int main()
{
    int no_of_queries;
    int bucket_size;
    int input_pkt_size;
    int output_pkt_size;
    int storage = 0;

    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);

    printf("Enter number of cycles: ");
    scanf("%d", &no_of_queries);

    printf("Enter output packet size (leak rate): ");
    scanf("%d", &output_pkt_size);

    for (int i = 0; i < no_of_queries; i++)
    {
        printf("\nCycle %d\n", i + 1);

        printf("Enter incoming packet size: ");
        scanf("%d", &input_pkt_size);

        int size_left = bucket_size - storage;

        if (input_pkt_size <= size_left)
        {
            storage += input_pkt_size;
            printf("Packets added: %d\n", input_pkt_size);
        }
        else
        {
            printf("Packets added: %d\n", size_left);
            printf("Packet loss: %d\n", input_pkt_size - size_left);

            storage = bucket_size;
        }

        printf("Buffer size = %d out of %d\n", storage, bucket_size);

        if (storage >= output_pkt_size)
            storage -= output_pkt_size;
        else
            storage = 0;

        printf("After leaking, buffer size = %d\n", storage);
    }

    return 0;
}
