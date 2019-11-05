#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long i, j, n;
	vector<long long> prime;
	long long arr[100001] = { 0, };
	bool isprime;
	long long cnt = 1;
	long long mul = 2;

	scanf("%lld", &n);

	prime.push_back(2);
	arr[2] = 1;

	for (i = 4; i <= n; i += 2)
	{
		arr[i] = 1;
	}

	for (i = 3; i * i <= n; i += 2)
	{
		isprime = true;

		for (j = 0; j < prime.size() && prime[j]*prime[j] <= i; j++)
		{
			if (!(i%prime[j]))
			{
				isprime = false;

				break;
			}
		}

		if (isprime)
		{
			arr[i] = ++cnt;

			prime.push_back(i);
		}
	}

	for (i = 1; i < prime.size(); i++)
	{
		if (mul < n)
		{
			mul *= prime[i];
		}

		for (j = prime[i] * 2; j <= n; j += prime[i])
		{
			arr[j] = arr[prime[i]];
		}
	}

	for (i = 2; i <= n; i++)
	{
		if (arr[i] == 0)
		{
			arr[i] = ++cnt;
		}
	}

	for (i = 2; i <= n; i++)
	{
		printf("%lld ", arr[i]);
	}

	return 0;
}