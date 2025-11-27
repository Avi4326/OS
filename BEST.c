#include <stdio.h>

int main() {

    int m, n;

    printf("Enter number of blocks: ");
    scanf("%d", &m);
    int blockSize[m];

    printf("Enter block sizes:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);
    int processSize[n], allocation[n];

    printf("Enter process sizes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }

    // BEST FIT
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nBest Fit Allocation:\n");
    printf("Process\tSize\tBlock\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("P%d\t%d\tB%d\n", i+1, processSize[i], allocation[i]+1);
        else
            printf("P%d\t%d\tNot Allocated\n", i+1, processSize[i]);
    }

    return 0;
}
