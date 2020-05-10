#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

#define MOD 998244353

using namespace std;

long long exp(long long base, long long pw)
{
	vector<long long> bits;

	if (base == 0)
	{
		return 0;
	}

	while (pw)
	{
		bits.push_back(pw % 2);

		pw /= 2;
	}

	long long temp;

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

using namespace std;

int main()
{
	long long n, m, l, r;

	scanf("%lld %lld %lld %lld", &n, &m, &l, &r);

	long long base;

	base = r - l + 1;

	long long sol;
	long long bit = 0;

	if (n % 2 && m % 2)
	{
		bit = 1;
	}

	sol = exp(base%MOD, n*m % (MOD - 1));

	if (bit)
	{
		printf("%lld\n", sol);

		return 0;
	}

	sol = (sol + base % 2) % MOD;

	sol = sol*div(2) % MOD;

	printf("%lld\n", sol);

	return 0;
}