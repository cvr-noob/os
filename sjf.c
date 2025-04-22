#include <stdio.h>
#include <stdlib.h>

typedef struct Process
{
    int id, at, bt, ct, wt, tat;
} process;

int cmp_bt(const void *a, const void *b);

int main()
{
    int n;
    printf("Enter no. of processes: ");
    scanf("%d", &n);

    process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        printf("\nEnter arrival & burst times for p[%d]: ", p[i].id);
        scanf("%d%d", &p[i].at, &p[i].bt);
    }

    qsort(p, n, sizeof(p), cmp_bt);

    p[0].ct = p[0].at + p[0].bt;
    int total_tat = p[0].tat = p[0].ct - p[0].at;
    int total_wt = p[0].wt = p[0].tat - p[0].bt;

    for (int i = 1; i < n; i++)
    {
        p[i].ct = p[i - 1].ct + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        total_tat += p[i].tat;
        total_wt += p[i].wt;
    }

    printf("\nAverage waiting time: %.2f", (float)total_wt / n);
    printf("\nAverage turnaround time: %.2f", (float)total_tat / n);

    printf("\n%-5s | %-12s | %-10s | %-15s | %-12s | %-16s\n",
           "PID", "Arrival Time", "Burst Time", "Completion Time", "Waiting Time", "Turnaround Time");
    printf("---------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
        printf("%-5d | %-12d | %-10d | %-15d | %-12d | %-16d\n",
               p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);

    return 0;
}

int cmp_bt(const void *a, const void *b)
{
    return ((process *)a)->bt - ((process *)b)->bt;
}