#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>

#define MOD 1000000007

using namespace std;

int main()
{
	vector<long long> prime, list;
	int i, j;
	bool isprime;
	long long a, b, temp;
	long long sol = 1;
	long long q;
	long long pw;

	prime.push_back(2);

	for (i = 3; i <= 31622; i += 2)
	{
		isprime = true;

		for (j = 0; j < prime.size() && prime[j] * prime[j] <= i; j++)
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

	scanf("%lld %lld", &a, &b);

	for(j=0;j<prime.size()&&a!=1&&prime[j]*prime[j]<=a;j++)
	{
		if (!(a%prime[j]))
		{
			list.push_back(prime[j]);

			while (!(a%prime[j]))
			{
				a /= prime[j];
			}
		}
	}

	if (a != 1)
	{
		list.push_back(a);
	}

	for (i = 0; i < list.size(); i++)
	{
		temp = b;
		q = 0;

		while (temp >= list[i])
		{
			q = (q + temp / list[i]) % (MOD - 1);

			temp /= list[i];
		}

		pw = list[i];

		while (q)
		{
			if (q % 2)
			{
				sol = (sol*pw) % MOD;
			}

			q /= 2;

			pw = pw*pw%MOD;
		}
	}

	printf("%lld\n", sol);

	return 0;
}