#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

#define MOD 998244353 

using namespace std;

int main()
{
	int n, m;
	int i, j;
	long long dp = 1;

	scanf("%d %d", &n, &m);

	for (i = 1; i < m; i++)
	{
		dp = dp * 2 % MOD;
	}

	for (i = 1; i < n; i++)
	{
		dp = dp * 2 % MOD;
	}

	dp = dp * 4 % MOD;

	printf("%lld\n", dp);

	return 0;
}