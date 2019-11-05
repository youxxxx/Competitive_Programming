#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

int main()
{
	int n;
	vector<int> prime;
	vector<int> arr, sol;
	bool isprime;
	int cnt[200001] = { 0, };
	int input;
	int i, j;
	int ptr;
	int lmax = 0;

	scanf("%d", &n);

	for (i = 0; i < n * 2; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);

		if (input > lmax)
		{
			lmax = input;
		}
	}

	prime.push_back(2);

	for (i = 3; i <= lmax; i += 2)
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

	ptr = prime.size() - 1;

	sort(arr.begin(), arr.end(), greater<int>());

	for (i = 0; i < 2 * n; i++)
	{
		if (arr[i] > 200000)
		{
			if (ptr >= 0)
			{
				while (prime[ptr] > arr[i])
				{
					ptr--;
				}

				if (prime[ptr] == arr[i])
				{
					cnt[ptr + 1]++;

					sol.push_back(ptr + 1);
				}
			}
		}

		else
		{
			if (cnt[arr[i]] > 0)
			{
				cnt[arr[i]]--;

				continue;
			}

			if (ptr >= 0)
			{
				while (prime[ptr] > arr[i])
				{
					ptr--;
				}

				if (ptr != -1 && prime[ptr] == arr[i])
				{
					cnt[ptr + 1]++;

					sol.push_back(ptr + 1);
				}

				else
				{
					for (j = 0; j < prime.size() && prime[j] * prime[j] <= arr[i]; j++)
					{
						if (!(arr[i] % prime[j]))
						{
							break;
						}
					}

					cnt[arr[i] / prime[j]]++;
					sol.push_back(arr[i]);
				}
			}

			else
			{
				for (j = 0; j < prime.size() && prime[j] * prime[j] <= arr[i]; j++)
				{
					if (!(arr[i] % prime[j]))
					{
						break;
					}
				}

				cnt[arr[i] / prime[j]]++;
				sol.push_back(arr[i]);
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", sol[i]);
	}

	return 0;
}