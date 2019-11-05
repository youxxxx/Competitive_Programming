#include<cstdio>

int main()
{
	int n, m, q, target;
	char input[13];
	int		st[4096] = { 0, };
	int w[100];
	int i, j, k;
	int base;
	int sum;
	int dp[100];

	scanf("%d %d %d", &n, &m, &q);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &w[i]);
	}

	for (i = 0; i < m; i++)
	{
		scanf("%s", input);

		base = 1;
		sum = 0;

		for (j = 0; j < n; j++)
		{
			sum += base * (input[j] - '0');
		}

		st[sum]++;
	}

	for (i = 0; i < q; i++)
	{
		scanf("%s %d", input, &target);

		base = 1;
		sum = 0;

		for (j = 0; j < n; j++)
		{

		}
	}
}