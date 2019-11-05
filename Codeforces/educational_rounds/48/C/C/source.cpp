#include<cstdio>

using namespace std;

int main()
{
	int n;
	unsigned long long int sum[4] = { 0, };
	unsigned long long int max = 0;
	unsigned long long int acc0 = 0, acc1 = 0;
	unsigned long long int *psum[2];
	int *g[2];
	int i;

	scanf("%d", &n);

	g[0] = new int[n];
	g[1] = new int[n];
	psum[0] = new unsigned long long int[n];
	psum[1] = new unsigned long long int[n];

	for (i = 0; i < n; i++)
	{
		scanf("%d", &g[0][i]);
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d", &g[1][i]);
	}

	for (i = n - 1; i >= 0; i--)
	{
		acc0 += g[0][i];
		acc1 += g[1][i];

		psum[0][i] = acc0;
		psum[1][i] = acc1;
	}

	for (i = 1; i < n; i++)
	{
		sum[0] += (unsigned long long int)g[0][i] * (unsigned long long int)i;
	}

	for (i = 0; i < n; i++)
	{
		sum[0] += (unsigned long long int)g[1][n - i - 1] * (unsigned long long int)(i + n);
	}
	
	for (i = 0; i < n; i++)
	{
		sum[1] += (unsigned long long int)g[1][i] * (unsigned long long int)(i + 1);
	}

	for (i = 0; i < n - 1; i++)
	{
		sum[1] += (unsigned long long int)g[0][n - i - 1] * (unsigned long long int)(i + n + 1);
	}

	max = sum[0];
	if (max < sum[1])max = sum[1];

	sum[2] = sum[0];
	sum[3] = sum[1];
	
	for (i = 1; i < n; i++)
	{
		sum[2] -= (psum[0][i-1] + psum[1][i-1]) * 2;
		sum[3] -= (psum[0][i-1] + psum[1][i-1]) * 2;
		sum[2] += g[i % 2][i] * (i * 2) + g[!(i % 2)][i] * (i * 2 + 1);
		sum[3] += g[i % 2][i] * (i * 2) + g[!(i % 2)][i] * (i * 2 + 1);

		if (sum[2] > max)max = sum[2];
		if (sum[3] > max)max = sum[3];
	}

	printf("%I64u", max);

	return 0;
}