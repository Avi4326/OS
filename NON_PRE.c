#include <stdio.h>

int main() {
    int n, i, j, temp;
    int bt[20], wt[20], tat[20], priority[20], p[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        printf("P%d Priority: ", i + 1);
        scanf("%d", &priority[i]);
        p[i] = i + 1;  // Process ID
    }

    // Sort by priority (lower number = higher priority)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(priority[i] > priority[j]) {
                // Swap priority
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                // Swap burst times
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process IDs
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;

    // Calculate waiting time
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n", p[i], bt[i], priority[i], wt[i], tat[i]);
    }

    return 0;
}
