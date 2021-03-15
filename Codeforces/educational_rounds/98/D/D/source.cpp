#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

#define MOD 998244353

long long exp(long long base, long long pw)
{
	long long rvalue = 1;

	while (pw)
	{
		if (pw % 2)
		{
			rvalue = rvalue*base%MOD;
		}

		base = base*base%MOD;

		pw /= 2;
	}

	return rvalue;
}

long long div(long long base)
{
	return exp(base, MOD - 2);
}

int main()
{
	//freopen("input.txt", "r", stdin);

	long long n;

	scanf("%lld", &n);

	long long dp[2];

	dp[0] = 1;
	dp[1] = 0;

	for (long long i = 1; i < n; i++)
	{
		long long bit = i % 2;

		dp[bit] = (dp[bit] + dp[!bit]) % MOD;
	}

	printf("%lld\n", dp[!(n % 2)] * div(exp(2, n)) % MOD);

	return 0;
}