#include <stdio.h>

int main()
{
    int no_of_queries = 4;
    int bucket_size = 10;
    int input_pkt_size = 4;
    int output_pkt_size = 1;
    int storage = 0;

    for (int i = 0; i < no_of_queries; i++)
    {
        printf("\nCycle %d\n", i + 1);

        int size_left = bucket_size - storage;

        if (input_pkt_size <= size_left)
        {
            storage += input_pkt_size;
            printf("Packets added: %d\n", input_pkt_size);
        }
        else
        {
            storage += size_left;
            printf("Packets added: %d\n", size_left);
            printf("Packet loss: %d\n", input_pkt_size - size_left);
        }

        printf("Buffer size = %d out of bucket size = %d\n", storage, bucket_size);

        if (storage >= output_pkt_size)
            storage -= output_pkt_size;
        else
            storage = 0;

        printf("After leaking, buffer size = %d\n", storage);
    }

    return 0;
}
