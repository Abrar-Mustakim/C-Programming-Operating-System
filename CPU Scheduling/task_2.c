#include <stdio.h>

// mustakim@DESKTOP-Q2KTU5Q:~/CPU Scheduling$ gcc task_2.c -o outputs && ./outputs
// Enter the number of processes: 4
// Enter burst times for each process:
// Burst time for Process 1: 53
// Burst time for Process 2: 17
// Burst time for Process 3: 68
// Burst time for Process 4: 24
// Enter time quantum: 20

// Process CT      TAT     WT
// P1      134     134     81
// P2      37      37      20
// P3      162     162     94
// P4      121     121     97

// Average Waiting Time: 73.00
// Average Turnaround Time: 113.50

void findCompletionTime(int n, int bt[], int quantum) {
    int wt[n], tat[n];
    int rem_bt[n];
    int t = 0;
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
    printf("\nProcess\tCT\tTAT\tWT\n");
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i + 1, tat[i], tat[i], wt[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int burst_time[n];
    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Burst time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    int quantum;
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    findCompletionTime(n, burst_time, quantum);
    return 0;
}
