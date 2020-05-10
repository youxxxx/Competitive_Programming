#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

int main()
{
	long long n, MOD;
	long long fact[250001];

	scanf("%lld %lld", &n, &MOD);

	long long sol = 0;

	fact[1] = 1;

	for (long long i = 2; i <= n; i++)
	{
		fact[i] = fact[i - 1] * i%MOD;
	}

	for (long long i = 1; i < n; i++)
	{
		long long add;

		add = (n - i + 1)*(n - i + 1) % MOD*fact[i] % MOD*fact[n - i] % MOD;

		sol = (sol + add) % MOD;
	}

	sol = (sol + fact[n]) % MOD;

	printf("%lld\n", sol);

	return 0;
}