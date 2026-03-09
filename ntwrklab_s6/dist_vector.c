#include <stdio.h>

#define MAX 10
#define INF 999

int main() {
    int n, i, j, k;
    int cost[MAX][MAX];
    int dist[MAX][MAX];
    int nextHop[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            dist[i][j] = cost[i][j];
            
            if(i == j)
                nextHop[i][j] = i;
            else if(cost[i][j] != INF)
                nextHop[i][j] = j;
            else
                nextHop[i][j] = -1;
        }
    }

   
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nextHop[i][j] = nextHop[i][k];
                }
            }
        }
    }

    
    for(i = 0; i < n; i++) {
        printf("\nRouting table for router %d:\n", i+1);
        printf("Destination\tNext Hop\tDistance\n");

        for(j = 0; j < n; j++) {
            printf("%d\t\t%d\t\t%d\n",
                   j+1,
                   nextHop[i][j] + 1,
                   dist[i][j]);
        }
    }

    return 0;
}

