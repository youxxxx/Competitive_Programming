#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, m, k;
	int arr[50][20001];
	int acc[50][20001];
	int dp[50][20001];
	int lmax[50][20001];
	int rmax[50][20001];

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		acc[i][0] = 0;

		for (int j = 1; j <= m; j++)
		{
			acc[i][j] = acc[i][j - 1] + arr[i][j - 1];
		}
	}

	int sol = 0;

	for (int j = k; j <= m; j++)
	{
		dp[0][j] = acc[0][j] - acc[0][j - k];

		if (n > 1)
		{
			dp[0][j] += acc[1][j] - acc[1][j - k];
		}

		if (dp[0][j] > sol)
		{
			sol = dp[0][j];
		}

		int curmax = 0;

		for (int j = k; j <= m; j++)
		{
			if (dp[0][j] > curmax)
			{
				curmax = dp[0][j];
			}

			lmax[0][j] = curmax;
		}

		curmax = 0;

		for (int j = m; j >= k; j--)
		{
			if (dp[0][j] > curmax)
			{
				curmax = dp[0][j];
			}

			rmax[0][j] = curmax;
		}

		if (curmax > sol)
		{
			sol = curmax;
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = k; j <= m; j++)
		{
			int curmax = 0;

			int lb, ub;

			lb = j - k;
			ub = j + k;

			int val;

			val = acc[i][j] - acc[i][j - k];

			if (i < n - 1)
			{
				val += acc[i + 1][j] - acc[i + 1][j - k];
			}

			if (lb >= k)
			{
				int cand;

				cand = lmax[i - 1][lb] + val;

				if (cand > curmax)
				{
					curmax = cand;
				}
			}

			if (ub <= m)
			{
				int cand;

				cand = rmax[i - 1][ub] + val;

				if (cand > curmax)
				{
					curmax = cand;
				}
			}

			lb = j - k + 1 > k ? j - k + 1 : k;
			ub = j + k - 1 < m ? j + k - 1 : m;

			for (int l = lb; l <= ub; l++)
			{
				int cand;

				if (l < j)
				{
					cand = dp[i - 1][l] - (acc[i][l] - acc[i][j - k]) + val;
				}

				else
				{
					cand = dp[i - 1][l] - (acc[i][j] - acc[i][l - k]) + val;
				}

				if (cand > curmax)
				{
					curmax = cand;
				}
			}

			if (curmax > sol)
			{
				sol = curmax;
			}

			dp[i][j] = curmax;
		}

		int curmax = 0;

		for (int j = k; j <= m; j++)
		{
			if (dp[i][j] > curmax)
			{
				curmax = dp[i][j];
			}

			lmax[i][j] = curmax;
		}

		curmax = 0;

		for (int j = m; j >= k; j--)
		{
			if (dp[i][j] > curmax)
			{
				curmax = dp[i][j];
			}

			rmax[i][j] = curmax;
		}
	}

	printf("%d\n", sol);

	return 0;
}