#include <stdio.h>

void findWaitingTime(char *name, int n, int bt[], int rt[])
{
    int count, time, remain = n, flag = 0, tq = 4;
    int wt = 0, at[10];

    for (count = 0; count < n; count++)
    {
        rt[count] = bt[count];
    }
    for (time = 0, count = 0; remain != 0;)
    {
        if (rt[count] <= tq && rt[count] > 0)
        {
            time += rt[count];
            rt[count] = 0;
            flag = 1;
        }
        else if (rt[count] > 0)
        {
            rt[count] -= tq;
            time += tq;
        }
    }
    if (rt[count] == 0 && flag == 1)
    {
        remain--;
        printf("P[%d]\t|\t%d\t|\t%d\n", count + 1, time - at[count], time - at[count] - bt[count]);
        wt += time - at[count] - bt[count];
        flag = 0;
    }
    if (count == n - 1)
        count = 0;
    else if (at[count] <= time)
        count++;
    else
        count = 0;
}

void findTurnAroundTime(char *name, int n, int bt[], int wt[], int rt[])
{
    int count, time, remain = n, flag = 0, tq = 4;
    int tat = 0, at[10];

    for (count = 0; count < n; count++)
    {
        rt[count] = bt[count];
    }
    for (time = 0, count = 0; remain != 0;)
    {
        if (rt[count] <= tq && rt[count] > 0)
        {
            time += rt[count];
            rt[count] = 0;
            flag = 1;
        }
        else if (rt[count] > 0)
        {
            rt[count] -= tq;
            time += tq;
        }
    }
    if (rt[count] == 0 && flag == 1)
    {
        remain--;
        printf("P[%d]\t|\t%d\t|\t%d\n", count + 1, time - at[count], time - at[count] - bt[count]);
        tat += time - at[count];

        flag = 0;
    }
    if (count == n - 1)
        count = 0;
    else if (at[count] <= time)
        count++;
    else
        count = 0;
}