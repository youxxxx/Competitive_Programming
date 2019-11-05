#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

#define MOD 998244353

using namespace std;

int main()
{
	long long dp[502][502];
	long long lmin[501][501];
	long long curidx;
	long long arr[501];
	long long n, m;
	long long i, j, k;
	long long val, val2;

	scanf("%lld %lld", &n, &m);

	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	for (i = 1; i <= n; i++)
	{
		curidx = i;

		lmin[i][i] = i;

		for (j = i + 1; j <= n; j++)
		{
			if (arr[j] < arr[curidx])
			{
				curidx = j;
			}

			lmin[i][j] = curidx;
		}
	}

	for (i = 1; i <= n; i++)
	{
		dp[i][i] = dp[i][i - 1] = 1;
	}

	dp[n + 1][n] = 1;

	for (i = 1; i < n; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			curidx = lmin[j][j + i];

			val = 0;
			val2 = 0;

			for (k = j; k <= curidx; k++)
			{
				val = (val + (dp[j][k - 1] * dp[k][curidx - 1]) % MOD) % MOD;
			}

			for (k = curidx; k <= j + i; k++)
			{
				val2 = (val2 + (dp[curidx + 1][k] * dp[k + 1][j + i]) % MOD) % MOD;
			}

			dp[j][j + i] = val*val2%MOD;
		}
	}

	printf("%lld\n", dp[1][n]);

	return 0;
}