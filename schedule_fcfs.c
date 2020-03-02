#include <stdio.h>

void findWaitingTime(char *name, int n, int bt[], int wt[])
{

	wt[0] = 0;

	for (int i = 1; i < n; i++)
		wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnAroundTime(char *name, int n, int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n; i++)
		tat[i] = bt[i] + wt[i];
}

void findavgTime(char *name, int n, int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	findWaitingTime(name, n, bt, wt);

	findTurnAroundTime(name, n, bt, wt, tat);

	printf("Processes Burst time Waiting time Turn around time\n");

	for (int i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf(" %d ", (i + 1));
		printf("	 %d ", bt[i]);
		printf("	 %d", wt[i]);
		printf("	 %d\n", tat[i]);
	}
	int s = (float)total_wt / (float)n;
	int t = (float)total_tat / (float)n;
	printf("Average waiting time = %d\n", s);
	printf("Average turn around time = %d\n", t);
}
