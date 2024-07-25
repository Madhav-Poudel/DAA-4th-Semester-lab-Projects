#include <stdio.h>
#include <limits.h>

int visited[10] = {0}, cost[10][10], min, mincost = 0;

void input(int num) {
    int i, j;
    printf("\nEnter the adjacency matrix\n\n");
    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) {
            printf("value of cost[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &cost[i][j]);
        }
    }
}

void display(int num) {
    int i, j;
    printf("\nThe cost of adjacency matrix\n\n");
    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
}

void prims(int num) {
    int i, j, ne = 1, a, b, u, v;
    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) {
            if (cost[i][j] == 0) {
                cost[i][j] = INT_MAX;
            }
        }
    }
    visited[0] = 1;

    printf("\nEdges in the MST:\n");

    while (ne < num) {
        min = INT_MAX;
        for (i = 0; i < num; i++) {
            for (j = 0; j < num; j++) {
                if (cost[i][j] < min) {
                    if (visited[i] != 0) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0) {
            printf("Edge %d: (%d - %d) cost: %d\n", ne++, a + 1, b + 1, min);
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = INT_MAX;
    }
    printf("\nMinimum cost = %d\n", mincost);
}

int main() {
    int num;
    printf("\n\t\t\tPrim's Algorithm");
    printf("\n\nEnter the number of nodes: ");
    scanf("%d", &num);
    input(num);
    display(num);
    prims(num);
    return 0;
}