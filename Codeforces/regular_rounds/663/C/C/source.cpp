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

#define MOD 1000000007

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

int main()
{
	//freopen("input.txt", "r", stdin);

	long long n;

	scanf("%lld", &n);

	long long sol = 1;

	for (long long i = 2; i <= n; i++)
	{
		sol = sol*i%MOD;
	}

	printf("%lld\n", (sol - exp(2, n - 1) + MOD) % MOD);

	return 0;
}