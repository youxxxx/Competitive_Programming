#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

bool primality(vector<long long> &prime, long long target)
{
	int i;
	bool isprime = true;

	if (target == 1)
	{
		return false;
	}

	for (i = 0; i < prime.size() && prime[i] * prime[i] <= target; i++)
	{
		if (!(target%prime[i]))
		{
			isprime = false;

			break;
		}
	}

	return isprime;
}

int main()
{
	int i, j;
	vector<long long> prime;
	int n;
	vector<long long> arr;
	long long input;
	long long sum = 0;
	vector<vector<long long>> box;
	vector<long long> cur, prev;
	int level = 0;
	bool isprime;

	prime.push_back(2);

	for (i = 3; i < 4473; i++)
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

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);

		sum += input;
	}

	for (i = arr.size() - 1; i >= 0; i--)
	{
		if (primality(prime, arr[i]) && primality(prime, sum - arr[i]))
		{
			cur.push_back(arr[i]);

			arr.erase(arr.begin() + i);
		}
	}

	if (cur.empty())
	{
		for (i = arr.size() - 1; i >= 0; i--)
		{
			if (primality(prime, arr[i]) || primality(prime, sum - arr[i]))
			{
				cur.push_back(arr[i]);

				arr.erase(arr.begin() + i);
			}
		}
	}

	if (arr.empty())
	{
		for (i = 0; i < n - 1; i++)
		{
			printf("%lld %lld\n", arr[i], arr[n - 1]);
		}

		return 0;
	}

	box.push_back(cur);

	cur.clear();

	while (!arr.empty())
	{
		level++;

		prev = box[level - 1];

		for (i = arr.size() - 1; i >= 0; i--)
		{
			for (j = prev.size() - 1; j >= 0; j--)
			{
				if (primality(prime, arr[i] + prev[j]) && primality(prime, sum - arr[i] - prev[j]))
				{
					cur.push_back(arr[i]);

					printf("%lld %lld\n", arr[i], prev[j]);

					arr.erase(arr.begin() + i);

					prev.erase(prev.begin() + j);

					break;
				}
			}
		}

		if (!prev.empty && arr.empty())
		{
			for (i = 0; i < prev.size(); i++)
			{
				printf("%lld %lld\n", cur[0], prev[i]);
			}

			return 0;
		}

		else if (prev.empty())
		{
			for (i = 0; i < arr.size(); i++)
			{
				printf("%lld %lld\n", arr[i], box[0][0]);
			}

			return 0;
		}

		if (!arr.empty())
		{
			for (i = arr.size() - 1; i >= 0; i--)
			{
				for (j = prev.size() - 1; j >= 0; j--)
				{
					if (primality(prime, arr[i] + prev[j]) || primality(prime, sum - arr[i] - prev[j]))
					{
						cur.push_back(arr[i]);

						printf("%lld %lld\n", arr[i], prev[j]);

						arr.erase(arr.begin() + i);

						prev.erase(prev.begin() + j);

						break;
					}
				}
			}
		}

		if (!prev.empty && arr.empty())
		{
			for (i = 0; i < prev.size(); i++)
			{
				printf("%lld %lld\n", cur[0], prev[i]);
			}

			return 0;
		}

		else if (prev.empty())
		{
			for (i = 0; i < arr.size(); i++)
			{
				printf("%lld %lld\n", arr[i], box[0][0]);
			}

			return 0;
		}

		else
		{
			return 0;
		}

		if (!arr.empty())
		{
			for (i = 0; i < prev.size(); i++)
			{
				printf("%lld %lld\n", arr[0], prev[i]);
			}

			for (i = 1; i < arr.size(); i++)
			{
				printf("%lld %lld\n", arr[i - 1], arr[i]);
			}
		}
	}

	return 0;
}