#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long n, m, t;
	long long i, j;
	vector<long long> prime;
	scanf("%I64d", &t);

	prime.push_back(2);

	for (i = 3; i < 500000; i+=2)
	{
		for (j = 0; j < prime.size() && prime[j] * prime[j] <= i; j++)
		{
			if (!(i%prime[j]))
			{
				break;
			}
		}

		if (j == prime.size() || prime[j] * prime[j] > i)
		{
			prime.push_back(i);
		}
	}

	for (j = 0; j < t; j++)
	{
		scanf("%I64d %I64d", &n, &m);

		if (n - m != 1)
		{
			printf("NO\n");
		}

		else if (n + m < 500000)
		{
			if (binary_search(prime.begin(), prime.end(), n + m))
			{
				printf("YES\n");
			}

			else
			{
				printf("NO\n");
			}
		}

		else
		{
			for (i = 0; i < prime.size() && prime[i] * prime[i] <= n + m ; i++)
			{
				if (!((n + m) % prime[i]))
				{
					break;
				}
			}

			if (i == prime.size() || prime[i] * prime[i] > n + m)
			{
				printf("YES\n");
			}

			else
			{
				printf("NO\n");
			}
		}

	}

 	return 0;
}