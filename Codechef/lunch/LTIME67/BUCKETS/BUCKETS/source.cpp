#include<cstdio>

int main()
{
	int n, k;
	double prob[2][1000];
	int ball[2][1000];
	int i, j;
	int sum;

	scanf("%d %d", &n, &k);

	sum = 0;

	for (i = 0; i < k; i++)
	{
		scanf("%d", &ball[0][i]);

		sum += ball[0][i];
	}

	for (i = 0; i < k; i++)
	{
		prob[0][i] = (double)ball[0][i] / (double)sum;
	}

	for (i = 1; i < n; i++)
	{
		sum = 0;

		for (j = 0; j < k; j++)
		{
			scanf("%d", &ball[i % 2][j]);

			sum += ball[i % 2][j];
		}

		sum++;

		for (j = 0; j < k; j++)
		{
			prob[i % 2][j] = (prob[!(i % 2)][j] * ((double)ball[i % 2][j] + 1) + (1.0 - prob[!(i % 2)][j]) * ((double)ball[i % 2][j])) / (double)sum;
		}
	}

	for (i = 0; i < k; i++)
	{
		printf("%.7lf ", prob[!(n % 2)][i]);
	}

	return 0;
}