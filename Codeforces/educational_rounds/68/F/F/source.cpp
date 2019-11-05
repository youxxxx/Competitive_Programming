#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>

#define MOD 1000000007

using namespace std;

int main()
{
	long long dp[2][200001];
	long long n, m;
	long long pw = 1;
	long long sum = 0;
	vector<long long> arr;
	long long i, j;
	long long input;
	long long ub, lb;
	long long bound = -1;
	long long sol = 0;
	vector<long long> mullist;
	long long cur;
	long long div;

	freopen("input.txt", "r", stdin);

	cur = MOD - 2;

	while (cur)
	{
		mullist.push_back(cur % 2);

		cur /= 2;
	}

	memset(dp, -1, sizeof(dp));

	scanf("%lld %lld", &n, &m);

	arr.push_back(0);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);

		if (bound == -1)
		{
			sum += input;

			if (sum > m)
			{
				bound = i;
			}

			else if (sum == m)
			{
				bound = i + 1;

				pw = pw * 2 % MOD;
			}

			else
			{
				pw = pw * 2 % MOD;
			}
		}
	}

	if (sum <= m)
	{
		bound = n;
	}

	ub = 0;

	dp[0][0] = 1;

	sum = 0;

	for (i = 1; i <= bound; i++)
	{
		sum += arr[i];

		dp[i % 2][0] = 1;

		for (j = 1; j < i; j++)
		{
			if (sum + j <= m)
			{
				dp[i % 2][j] = (dp[!(i % 2)][j] + dp[!(i % 2)][j - 1]) % MOD;
			}

			else
			{
				sol = (sol + dp[!(i % 2)][j] * (i-1) * 2 % MOD) % MOD;

				dp[i % 2][j] = 0;
			}
		}

		if (sum + i <= m)
		{
			dp[i % 2][i] = dp[i % 2][i - 1];
		}

		else
		{
			//sol = (sol + dp[!(i % 2)][i - 1] * (i - 1) % MOD) % MOD;

			dp[i % 2][j] = 0;
		}

		sol = sol * 2 % MOD;
	}

	for (i = 0; i <= bound; i++)
	{
		if (dp[bound % 2][i] == -1)
		{
			break;
		}

		sol = (sol + dp[bound % 2][i] * bound % MOD) % MOD;
	}

	for (i = bound + 1; i <= n; i++)
	{
		pw = pw * 2 % MOD;
		sol = sol * 2 % MOD;
	}

	cur = pw;

	div = 1;

	for (i = 0; i < mullist.size(); i++)
	{
		if (mullist[i])
		{
			div = (div * cur) % MOD;
		}

		cur = (cur*cur)%MOD;
	}

	sol = (sol*div)%MOD;

	printf("%lld\n", sol);

	return 0;
}