#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

#define MOD 1000000007

using namespace std;

int main()
{
	long long n, m;

	scanf("%lld %lld", &n, &m);

	long long change[11][1001];

	long long sol = 0;

	change[0][0] = 1;

	for (long long i = 1; i <= n; i++)
	{
		change[0][i] = 0;
	}

	for (long long i = 1; i < m; i++)
	{
		change[i][0] = 1;

		for (long long j = 1; j <= n; j++)
		{
			change[i][j] = 0;

			for (long long k = 0; k <= j; k++)
			{
				change[i][j] = (change[i][j] + change[i - 1][k] * (j - k + 1) % MOD) % MOD;
			}
		}
	}

	long long acc[1001];

	acc[0] = 1;

	for (long long i = 1; i <= n; i++)
	{
		acc[i] = (acc[i - 1] + change[m - 1][i]) % MOD;
	}

	for (long long i = 1; i <= n; i++)
	{
		for (long long j = i; j <= n; j++)
		{
			sol = (sol + acc[j - i]) % MOD;
		}
	}

	printf("%lld\n", sol);

	return 0;
}