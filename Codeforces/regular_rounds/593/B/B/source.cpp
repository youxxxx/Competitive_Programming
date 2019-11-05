#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

#define MOD 1000000007

using namespace std;

long long exp(long long base, long long pw)
{
	long long temp, rvalue;

	rvalue = 1;
	temp = base;

	while (pw)
	{
		if (pw % 2)
		{
			rvalue = rvalue*temp%MOD;
		}

		temp = temp*temp%MOD;

		pw /= 2;
	}

	return rvalue;
}

int main()
{
	long long n, m;
	long long b;

	scanf("%lld %lld", &n, &m);

	b = (exp(2, m) + MOD - 1) % MOD;

	printf("%lld\n", exp(b, n));

	return 0;
}