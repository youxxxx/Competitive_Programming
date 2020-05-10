#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long x;
	vector<long long> prime;

	scanf("%lld", &x);

	if (x == 2)
	{
		printf("2\n");

		return 0;
	}

	prime.push_back(2);

	for (long long i = 3; i < x; i++)
	{
		bool isprime = true;

		for (int j = 0; j < prime.size() && prime[j] * prime[j] <= i; j++)
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

	for (long long i = x;; i++)
	{
		bool isprime = true;

		for (int j = 0; j < prime.size() && prime[j] * prime[j] <= i; j++)
		{
			if (!(i%prime[j]))
			{
				isprime = false;

				break;
			}
		}

		if (isprime)
		{
			printf("%lld\n", i);

			return 0;
		}
	}

	return 0;
}