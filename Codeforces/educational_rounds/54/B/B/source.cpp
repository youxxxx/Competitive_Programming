#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	long long n, d;
	vector<long long> prime;
	long long i, j;
	bool isprime;

	scanf("%I64d", &n);

	prime.push_back(2);

	if (!(n % 2))
	{
		printf("%I64d", n / 2);

		return 0;
	}

	for (i = 3; i*i<=n; i+=2)
	{
		isprime = true;

		for (j = 0; j < prime.size() && prime[j]*prime[j]<=i; j++)
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

			if (!(n%i))
			{
				if (n == i)
				{
					printf("1\n");
				}

				else
				{
					printf("%I64d\n", 1 + (n - i) / 2);
				}

				return 0;
			}
		}
	}

	if (!(n % 2))
	{
		printf("%I64d", n / 2);
	}

	printf("1\n");

	return 0;
}