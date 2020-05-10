#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstring>

using namespace std;

long long gcd(long long a, long long b)
{
	while (b != 0)
	{
		long long temp;

		a %= b;
		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	long long cases;

	scanf("%lld", &cases);

	vector<long long> prime;

	prime.push_back(2);

	for (long long i = 3; i < 100000; i += 2)
	{
		bool isprime = true;

		for (int j = 0; j < prime.size() && prime[j]*prime[j] <= i; j++)
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

	for (long long tc = 0; tc < cases; tc++)
	{
		long long n, m;

		scanf("%lld %lld", &n, &m);

		long long g;

		g = gcd(n, m);

		m /= g;

		long long sol = 1;

		for (int i = 0; i < prime.size() && m != 1; i++)
		{
			long long cnt = 0;

			while (!(m%prime[i]))
			{
				m /= prime[i];
				
				cnt++;
			}

			if (cnt != 0)
			{
				sol *= (prime[i] - 1)*(long long)pow((double)prime[i], cnt - 1);
			}
		}

		if (m != 1)
		{
			sol *= m - 1;
		}

		printf("%lld\n", sol);
	}

 	return 0;
}