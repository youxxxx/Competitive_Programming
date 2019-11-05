#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	vector<long long> arr;
	long long input;
	long long n;
	long long i, j;
	long long sol = 0;
	long long cur = 0;
	long long pw;
	long long lg[11] = { 0, };
	long long acc[11];
	long long mul[11] = { 0, };
	long long tot[11] = { 0, };
	long long temp;
	long long digit;
	long long MOD = 998244353;

	scanf("%lld", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);

		lg[(long long)log10((double)input) + 1]++;
	}

	acc[0] = 0;

	for (i = 1; i <= 10; i++)
	{
		acc[i] = acc[i - 1] + lg[i];
	}

	for (i = 1; i <= 10; i++)
	{
		pw = (long long)pow(10.0, i - 1) % MOD;

		for (j = 1; j < i; j++)
		{
			pw = pw * 10 % MOD;

			mul[i] = (((mul[i] + ((lg[j] * pw * 2) % MOD)) % MOD) % MOD);
		}

		mul[i] = (mul[i] + (((n - acc[i - 1])*pw % MOD) * 11 % MOD)) % MOD;
	}

	for (i = 0; i < n; i++)
	{
		temp = arr[i];

		for (j = 1; temp != 0 && j <= 10; j++)
		{
			digit = temp % 10;

			temp /= 10;

			tot[j] = (tot[j] + digit) % MOD;
		}
	}

	/*
	for (i = 0; i < n; i++)
	{
		temp = arr[i];

		for (j = 1; (j <= 10) && temp; j++)
		{
			digit = temp % 10;

			sol = (sol + (digit * mul[j]) % MOD) % MOD;

			temp /= 10;
		}
	}
	*/

	for (i = 1; i <= 10; i++)
	{
		sol = (sol + (tot[i] * mul[i]) % MOD) % MOD;
	}

	printf("%lld\n", sol % MOD);

	return 0;
}