#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define MOD 998244353

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
	long long n;
	long long k[1000001];
	vector<long long> arr[1000001];
	long long cnt[1000001] = { 0, };
	long long tot = 1;

	scanf("%lld", &n);

	for (long long i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		k[i] = input;

		for (long long j = 0; j < input; j++)
		{
			long long input2;

			scanf("%lld", &input2);

			arr[i].push_back(input2);

			cnt[input2]++;
		}

		tot = tot*input%MOD;
	};

	long long itemtot = 0;
	
	for (long long i = 1; i <= 1000000; i++)
	{
		if (cnt[i])
		{
			itemtot = (itemtot+cnt[i]) % MOD;
		}
	}

	long long sol = 0;

	for (long long i = 0; i < n; i++)
	{
		long long mult;

		mult = tot * div(k[i]) % MOD;

		long long sum = 0;

		for (long long j = 0; j < k[i]; j++)
		{
			sum = (sum + cnt[arr[i][j]]) % MOD;
		}

		sum = sum*mult%MOD;

		sol = (sol + sum) % MOD;
	}

	sol = sol*div(tot) % MOD;
	sol = sol*div(n) % MOD;
	sol = sol*div(n) % MOD;

	printf("%lld\n", sol);

	return 0;
}