#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n, m, k;
	long long i, j;
	long long *dp[2];
	long long min;

	scanf("%I64d %I64d %I64d", &n, &m, &k);

	dp[0] = new long long[n];
	dp[1] = new long long[n];

	for (i = 0; i < n; i++)
	{
		dp[0][i] = dp[1][i] = 0;
	}

	dp[0][0] = m;

	for (i = 1; i < n; i++)
	{
		dp[i % 2][0] = dp[!(i % 2)][0];

		for (j = 1; j < i&&j <= k; j++)
		{
			dp[i % 2][j] = (dp[!(i % 2)][j - 1] * (m - 1) + dp[!(i % 2)][j]) % 998244353;
		}

		if (j <= k)
		{
			dp[i % 2][j] = (dp[!(i % 2)][j - 1] * (m - 1)) % 998244353;
		}
	}

	printf("%I64d\n", dp[!(n % 2)][k]);

	return 0;
}