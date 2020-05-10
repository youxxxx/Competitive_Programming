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

using namespace std;

#define MOD 1000000007

long long exp(long long base, long long pw)
{
	long long temp;

	if (!base)
	{
		return 0;
	}

	temp = pw;

	vector<long long> bits;

	while (temp)
	{
		bits.push_back(temp % 2);

		temp /= 2;
	}

	long long rvalue = 1;

	temp = base;

	for (int i = 0; i < bits.size(); i++)
	{

		if (bits[i])
		{
			rvalue = rvalue*temp%MOD;
		}

		temp=temp*temp%MOD;
	}

	return rvalue;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	long long val[100001];

	long long n, k;

	scanf("%lld %lld", &k, &n);

	long long sol = 0;

	for (long long i = n; i >= 1; i--)
	{
		val[i] = exp(n / i, k);

		for (long long j = i * 2; j <= n; j += i)
		{
			val[i] = (val[i] + MOD - val[j]) % MOD;
		}

		sol = (sol+(i*val[i] % MOD)) % MOD;
	}

	printf("%lld\n", sol);

	return 0;
}