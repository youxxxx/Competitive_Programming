#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

#define MOD 1000000007

using namespace std;

long long exp(long long base, long long pw)
{
	vector<long long> bits;

	long long temp;

	temp = pw;

	while (temp)
	{
		bits.push_back(temp % 2);

		temp /= 2;
	}

	temp = base;

	long long rvalue = 1;

	for (int i = 0; i < bits.size(); i++)
	{
		if (bits[i])
		{
			rvalue = rvalue*temp%MOD;
		}

		temp = temp*temp%MOD;
	}

	return rvalue;
}

long long div(long long val)
{
	return exp(val, MOD - 2);
}

int main()
{
	long long r[2], c[2];
	long long sol[2] = { 1,1 };

	scanf("%lld %lld %lld %lld", &r[0], &c[0], &r[1], &c[1]);

	r[1] -= r[0];
	c[1] -= c[0];

	for (long long z = 0; z < 2; z++)
	{
		for (long long i = 1; i <= r[z] + c[z]; i++)
		{
			sol[z] = sol[z]*i%MOD;
		}

		for (long long i = 1; i <= r[z]; i++)
		{
			sol[z] = sol[z]*div(i) % MOD;
		}
		for (long long i = 1; i <= c[z]; i++)
		{
			sol[z] = sol[z]*div(i) % MOD;
		}
	}

	printf("%lld\n", sol[0] * sol[1] % MOD);

	return 0;
}