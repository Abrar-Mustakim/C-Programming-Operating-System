#include <stdio.h>


// mustakim@DESKTOP-Q2KTU5Q:~/CPU Scheduling$ gcc task_1.c -o outputs && ./outputs
// Enter the Total Number of Processes: 5
// Enter Details of 5 Processes
// Enter Arrival Time for Process 1: 0
// Enter Burst Time for Process 1: 5
// Enter Arrival Time for Process 2: 2
// Enter Burst Time for Process 2: 2
// Enter Arrival Time for Process 3: 3
// Enter Burst Time for Process 3: 7
// Enter Arrival Time for Process 4: 4
// Enter Burst Time for Process 4: 4
// Enter Arrival Time for Process 5: 5
// Enter Burst Time for Process 5: 5

// Process Completion Time Turnaround Time Waiting Time
// P2      4               2               0
// P1      7               7               2
// P4      11              7               3
// P5      16              11              6
// P3      23              20              13

// Average Waiting Time: 4.80
// Average Turnaround Time: 9.40









int main() {
    int arrival_time[10], burst_time[10], temp[10];
    int i, smallest, count = 0, time = 0, limit;
    double wait_time = 0, turnaround_time = 0, end;
    float average_waiting_time, average_turnaround_time;

    printf("Enter the Total Number of Processes: ");
    scanf("%d", &limit);

    printf("Enter Details of %d Processes\n", limit);
    for (i = 0; i < limit; i++) {
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];
    }

    burst_time[9] = 9999;
    printf("\nProcess\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (time = 0; count != limit; time++) {
        smallest = 9;
        for (i = 0; i < limit; i++) {
            if (arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0) {
                smallest = i;
            }
        }
        burst_time[smallest]--;
        if (burst_time[smallest] == 0) {
            count++;
            end = time + 1;
            wait_time += end - arrival_time[smallest] - temp[smallest];
            turnaround_time += end - arrival_time[smallest];
            printf("P%d\t%d\t\t%d\t\t%d\n", smallest + 1, (int)end, (int)(end - arrival_time[smallest]), (int)(end - arrival_time[smallest] - temp[smallest]));
        }
    }

    average_waiting_time = wait_time / limit;
    average_turnaround_time = turnaround_time / limit;

    printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);

    return 0;
}
