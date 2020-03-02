#include <stdio.h>

void findWaitingTime(char *name, int n, int bt[], int wt[])
{
    int i, j, total = 0, avg_wt;
    wt[0] = 0;

    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];

        total += wt[i];
    }

    avg_wt = (float)total / n;
    printf("Average waiting time %d\n",avg_wt);
}

void findTurnAroundTime(char *name, int n, int p[], int bt[], int wt[], int tat[])
{
    int i, total = 0, avg_tat;
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("\n%d\t\t  %d\t\t   %d\t\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    avg_tat = (float)total / n;
    printf("Average turnaround time %d\n",avg_tat);
}