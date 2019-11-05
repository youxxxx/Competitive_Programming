#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

#define MOD 998244353 

using namespace std;

int main()
{
	int n;
	vector<int> prime;
	vector<int>::iterator it, it2;
	int ptr1, ptr2;
	int i, j;
	bool isprime = false;
	vector<pair<int, int>> sol; 
	bool primality[1000000] = { 0, };

	scanf("%d", &n);

	prime.push_back(2);

	primality[2] = true;

	for (i = 3; i <= 1000000; i+=2)
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

		primality[i] = isprime;
	}

	it = lower_bound(prime.begin(), prime.end(), n);

	if (*it > n*(n - 1) / 2)
	{
		printf("-1\n");

		return 0;
	}

	for (i = 0; i < n; i++)
	{
		sol.push_back(make_pair(i + 1, (i + 1) % n + 1));
	}

	for (i = 0; i < n - 2 && sol.size() != *it; i+=4)
	{
		sol.push_back(make_pair(i + 1, (i + 2) % n + 1));

		if (sol.size() == *it)
		{
			break;
		}

		sol.push_back(make_pair(i + 2, (i + 3) % n + 1));
	}

	/*
	for (i = 1; i <= n / 2 && sol.size() != *it; i++)
	{
		for (j = 0; j < n&&sol.size() != *it; j++)
		{
			sol.push_back(make_pair(j + 1, (j + i) % n + 1));
		}
	}
	*/

	printf("%d\n", *it);

	for (i = 0; i < *it; i++)
	{
		printf("%d %d\n", sol[i].first, sol[i].second);
	}

	return 0;
}