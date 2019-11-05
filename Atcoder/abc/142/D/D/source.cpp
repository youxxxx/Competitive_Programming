#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
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
	long long a, b;
	vector<long long> prime;
	long long i, j;
	bool isprime;
	long long temp;
	long long cnt = 1;
	long long ub;

	scanf("%lld %lld", &a, &b);

	prime.push_back(2);

	temp = gcd(a, b);

	ub = (long long)sqrt(double(temp));

	for (i = 3; i <= ub; i += 2)
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

	for (i = 0; i < prime.size(); i++)
	{
		if (temp == 1 || prime[i] * prime[i] > temp)
		{
			break;
		}

		if (!(temp%prime[i]))
		{
			cnt++;

			while (!(temp%prime[i]))
			{
				temp /= prime[i];
			}
		}

		if (temp == 1 || prime[i] * prime[i] > temp)
		{
			break;
		}
	}

	if (temp != 1)
	{
		cnt++;
	}

	printf("%lld\n", cnt);

	return 0;
}