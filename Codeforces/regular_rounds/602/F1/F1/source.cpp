#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

#define MOD 998244353

using namespace std;

const long long pm2 = MOD - 2;

long long exp(long long base, long long pw)
{
	long long temp;
	vector<long long> bits;

	temp = pw;

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

		temp = (temp*temp) % MOD;
	}

	return rvalue;
}

int main()
{
	long long perm;
	long long comb[2001][2001], acc[2001][2001];
	long long temp;

	comb[0][0] = 1;
	acc[0][0] = 1;

	for (int i = 1; i <= 2000; i++)
	{
		comb[i][0] = comb[i][i] = 1;
		acc[i][0] = 1;

		for (int j = 1; j < i; j++)
		{
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];

			comb[i][j] %= MOD;

			acc[i][j] = acc[i][j - 1] + comb[i][j];

			acc[i][j] %= MOD;
		}

		acc[i][i] = (acc[i][i - 1] + 1) % MOD;
	}

	long long n, k;

	scanf("%lld %lld", &n, &k);

	if (k == 1)
	{
		printf("0\n");

		return 0;
	}

	vector<long long> arr;

	for (int i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		arr.push_back(input);
	}

	long long neut = 0, left;

	for (int i = 0; i < n; i++)
	{
		if (arr[(i - 1 + n) % n] == arr[i])
		{
			neut++;
		}
	}

	left = n - neut;

	long long base;

	base = exp(k, neut);

	long long sol = 0;

	for (int i = 1; i <= left; i++)
	{
		long long ub;
		long long add, sub;

		ub = i - 1 < left - i ? i - 1 : left - i;

		for (long long j = 0; j <= ub; j++)
		{
			long long other;

			other = exp(k - 2, left - i - j);

			sol = (sol + comb[left][i] * comb[left - i][j] % MOD * other % MOD) % MOD;
		}
	}

	sol = sol*base%MOD;

	printf("%lld\n", sol);

	return 0;
}