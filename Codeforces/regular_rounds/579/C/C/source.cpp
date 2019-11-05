#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

long long gcd(long long a, long long b)
{
	long long temp;

	while (b != 0)
	{
		a %= b;

		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	long long n;
	long long i, j;
	long long input, div, temp;
	vector<long long> prime;
	long long cnt;
	long long res = 1;
	bool isprime;

	prime.push_back(2);

	for (i = 3; i <= 1000000; i += 2)
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

	scanf("%lld", &n);

	scanf("%lld", &div);

	for (i = 1; i < n; i++)
	{
		scanf("%lld", &input);

		div = gcd(input, div);
	}
	
	temp = div;

	for (i = 0 ; i < prime.size(); i++)
	{
		if (temp < prime[i])
		{
			break;
		}

		cnt = 0;

		while (!(temp%prime[i]))
		{
			temp /= prime[i];

			cnt++;
		}

		res *= cnt + 1;
	}

	if (temp != 1)
	{
		res *= 2;
	}
	
	printf("%lld\n", res);

	return 0;
}