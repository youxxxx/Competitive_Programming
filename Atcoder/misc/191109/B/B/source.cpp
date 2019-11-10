#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

#define MOD 998244353
#define comb(n,r) (fact[(n)]*(div[(r)]*div[(n)-(r)]%MOD)%MOD)

using namespace std;

long long exp(long long base, long long pw)
{
	long long temp;
	long long rvalue = 1;

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
	long long n;
	long long fact[200001], div[200001];
	vector<long long> bits;
	vector<long long> depth[100001];
	long long temp;

	temp = MOD - 2;

	while (temp)
	{
		bits.push_back(temp % 2);

		temp /= 2;
	}

	scanf("%lld", &n);

	fact[0] = 1;
	div[0] = 1;
	fact[1] = 1;
	div[1] = 1;

	for (long long i = 2; i <= n * 2; i++)
	{
		long long temp;

		div[i] = 1;
		fact[i] = fact[i - 1] * i%MOD;

		temp = fact[i];

		for (int j = 0; j < bits.size(); j++)
		{
			if (bits[j])
			{
				div[i] = div[i] * temp%MOD;
			}

			temp = temp*temp%MOD;
		}
	}

	for (long long i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		depth[input].push_back(i);
	}

	if (depth[0].size() != 1 || depth[0][0] != 0)
	{
		printf("0\n");

		return 0;
	}

	long long acc = 1;
	long long sol = 1;

	for (long long i = 1; i < n; i++)
	{
		if (depth[i].empty() && acc != n)
		{
			printf("0\n");

			return 0;
		}

		sol = sol*exp(depth[i-1].size(),depth[i].size()) % MOD;

		acc += depth[i].size();

		if (acc == n)
		{
			break;
		}
	}

	printf("%lld\n", sol);

	return 0;
}