#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

#define MOD 1000000007

using namespace std;

long long exp(long long base, long long pw)
{
	vector<long long> bits;

	while (pw)
	{
		bits.push_back(pw % 2);

		pw /= 2;
	}

	long long temp;

	temp = base;

	long long rvalue = 1;

	for (long long i = 0; i < bits.size(); i++)
	{
		if (bits[i])
		{
			rvalue = rvalue*temp%MOD;
		}

		temp = temp*temp%MOD;
	}

	return rvalue;
}

long long divd(long long base, long long pw)
{
	return exp(exp(base, MOD - 2), pw);
}

int main()
{
	vector<long long> prime;

	prime.push_back(2);

	for (long long i = 3; i < 1000; i += 2)
	{
		bool isprime = true;

		for (long long j = 0; j < prime.size() && prime[j] * prime[j] <= i; j++)
		{
			if (!(i%prime[j]))
			{
				isprime = false;

				break;
			}
		}

		if (isprime)
		{
			prime.push_back(i);
		}
	}

	vector<long long> arr;
	long long n;
	map<long long, long long> tot, part[10001];

	scanf("%lld", &n);

	for (long long i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		arr.push_back(input);

		for (long long j = 0; j < prime.size() && input != 1; j++)
		{
			long long cnt = 0;

			if (input % prime[j])
			{
				continue;
			}

			while (input != 1 && !(input % prime[j]))
			{
				input /= prime[j];

				cnt++;
			}

			if (cnt)
			{
				part[i][prime[j]] = cnt;

				map<long long, long long>::iterator ret;

				ret = tot.find(prime[j]);

				if (ret == tot.end() || ret->second < cnt)
				{
					tot[prime[j]] = cnt;
				}
			}
		}

		if (input != 1)
		{
			tot[input] = 1;

			part[i][input] = 1;
		}
	}

	long long base = 1;

	for (map<long long, long long>::iterator it = tot.begin(); it != tot.end(); it++)
	{
		base = base*exp(it->first, it->second) % MOD;
	}

	long long sol = 0;

	for (long long i = 0; i < n; i++)
	{
		map<long long, long long>::iterator it;

		long long mult;

		mult = base;

		for (map<long long, long long>::iterator it = part[i].begin(); it != part[i].end(); it++)
		{
			mult = mult*divd(it->first, it->second) % MOD;
		}

		sol = (sol + mult) % MOD;
	}

	printf("%lld\n", sol);

	return 0;
}