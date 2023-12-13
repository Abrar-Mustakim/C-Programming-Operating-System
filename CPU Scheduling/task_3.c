#include <stdio.h>
#include <limits.h>

// mustakim@DESKTOP-Q2KTU5Q:~/CPU Scheduling$ gcc task_3.c -o outputs && ./outputs
// Enter the number of processes: 5
// Process 1:
// Arrival time: 0
// Burst time: 15
// Priority: 2
// Process 2:
// Arrival time: 14
// Burst time: 5
// Priority: 4
// Process 3:
// Arrival time: 3
// Burst time: 10
// Priority: 0
// Process 4:
// Arrival time: 9
// Burst time: 22
// Priority: 3
// Process 5:
// Arrival time: 7
// Burst time: 16
// Priority: 1
// Given details:
// AT      BT      PT
// 0      15      2
// 14      5      4
// 3      10      0
// 9      22      3
// 7      16      1

// Results:
// AT      BT      PT      CT      TAT      WT
// 0      0      2      41      41      26
// 14      0      4      68      54      49
// 3      0      0      13      10      0
// 9      0      3      63      54      32
// 7      0      1      29      22      6

// Average Turnaround Time: 36.20
// Average Waiting Time: 22.60


int jtime = 0;
int counter;
int n;
int at[20], bt[20], ct[20], pt[20], sts[20], wt[20];
void process_Ps()
{
    int index = -1;
    int highestPriority = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (at[i] <= jtime && sts[i] != 1)
        {
            if (pt[i] < highestPriority)
            {
                highestPriority = pt[i];
                index = i;
            }
        }
    }
    if (index != -1)
    {
        if (bt[index] > 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (at[i] <= jtime && sts[i] != 1 && i != index)
                {
                    wt[i]++; 
                }
            }
            bt[index]--;
            jtime++;
        }
        if (bt[index] == 0)
        {
            ct[index] = jtime;
            sts[index] = 1;
            counter--;
        }
    }
    else
    {
        jtime++;
    }
}
int main()
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    counter = n;
    for (int i = 0; i < n; i++)
    {
        printf("Process %d:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pt[i]);
        sts[i] = 0;
        ct[i] = 0;
        wt[i] = 0; 
    }
    printf("Given details:\n");
    printf("AT      BT      PT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d      %d      %d\n", at[i], bt[i], pt[i]);
    }
    while (counter != 0)
    {
        process_Ps();
    }
    printf("\nResults:\n");
    printf("AT      BT      PT      CT      TAT      WT\n");
    int totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++)
    {
        int turnaroundTime = ct[i] - at[i];
        int waitingTime = wt[i]; 
        totalTAT += turnaroundTime;
        totalWT += waitingTime;
        printf("%d      %d      %d      %d      %d      %d\n", at[i], bt[i], pt[i], ct[i], turnaroundTime, waitingTime);
    }

    float avgTAT = (float)totalTAT / n;
    float avgWT = (float)totalWT / n;

    printf("\nAverage Turnaround Time(TAT): %.2f\n", avgTAT);
    printf("Average Waiting Time(WT): %.2f\n", avgWT);

    return 0;
}
