#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool safe(long long x, long long y, long long n, long long m)
{
	return x >= 0 && x < n&&y >= 0 && y < m;
}

int main()
{
	long long n, m;
	long long i, j;
	long long **a, **b;
	long long **sa, **sb;

	//freopen("input.txt", "r", stdin);

	scanf("%I64d %I64d", &n, &m);

	a = new long long*[n];
	b = new long long*[n];
	sa = new long long*[n + m];
	sb = new long long*[n + m];

	for (i = 0; i < n; i++)
	{
		a[i] = new long long[m];

		for (j = 0; j < m; j++)
		{
			scanf("%I64d", &a[i][j]);
		}
	}

	for (i = 0; i < n; i++)
	{
		b[i] = new long long[m];

		for (j = 0; j < m; j++)
		{
			scanf("%I64d", &b[i][j]);
		}
	}

	for (i = 0; i < n + m; i++)
	{
		sa[i] = new long long[n + m];
		sb[i] = new long long[n + m];

		for (j = 0; j < n + m; j++)
		{
			sa[i][j] = sb[i][j] = 9999999999;
		}
	}

	for (i = 0; i < n + m; i++)
	{
		for (j = 0; j < n + m; j++)
		{
			if (!safe(i - j, j, n, m))
			{
				continue;
			}

			sa[i][j] = a[i - j][j];
			sb[i][j] = b[i - j][j];
		}

		sort(&sa[i][0], &sa[i][n + m]);
		sort(&sb[i][0], &sb[i][n + m]);

		for (j = 0; j < n + m; j++)
		{
			if (sa[i][j] != sb[i][j])
			{
				printf("NO\n");

				return 0;
			}
		}
	}

	printf("YES\n");

	return 0;
}