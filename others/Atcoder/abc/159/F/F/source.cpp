#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

#define MOD 998244353

using namespace std;

int main()
{
	int n;
	long long s;

	scanf("%d %lld", &n, &s);

	vector<long long> arr(3001);

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	long long sol = 0;
	long long dp[2][5001] = { 0, };

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= s; j++)
		{
			dp[i % 2][j] = dp[!(i % 2)][j];
		}

		if (arr[i] == s)
		{
			sol = (sol + (long long)(i + 1) * (long long)(n - i) % MOD) % MOD;
		}

		else if (arr[i] < s)
		{
			dp[i % 2][arr[i]] = (dp[i % 2][arr[i]] + (long long)(i + 1)) % MOD;

			for (int j = 1; j < s - arr[i]; j++)
			{
				dp[i % 2][j + arr[i]] = (dp[i % 2][j + arr[i]] + dp[!(i % 2)][j]) % MOD;
			}

			if (s - arr[i] > 0)
			{
				sol = (sol + dp[!(i % 2)][s - arr[i]] * (long long)(n - i) % MOD) % MOD;
			}
		}
	}

	printf("%lld\n", sol);

	return 0;
}