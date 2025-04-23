#include<stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], p[n], priority[n];
    printf("Enter burst times and priorities:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d", &bt[i], &priority[i]);
        p[i] = i + 1;
    }
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(priority[j] > priority[j + 1]) {
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    printf("\n%-15s %-15s %-15s %-15s %-15s\n", "Process", "Burst Time", "Priority", "Waiting Time", "Turnaround Time");
    for(i = 0; i < n; i++) {
        printf("P%-15d %-15d%-15d %-15d %-15d\n", p[i], bt[i], priority[i], wt[i], tat[i]);
    }

    return 0;
}
 
