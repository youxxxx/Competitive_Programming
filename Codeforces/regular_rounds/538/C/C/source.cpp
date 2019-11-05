#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	long long n, b;
	vector<long long> prime;
	long long i, j;
	bool isprime;
	vector<pair<long long, long long>> div;
	pair<long long, long long> cur;
	long long temp;
	long long cnt;
	long long min;

	scanf("%I64d %I64d", &n, &b);

	prime.push_back(2);

	for (i = 3; i * i <= b; i++)
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

	temp = b;

	for (i = 0; i < prime.size() && temp != 1; i++)
	{
		if (!(temp%prime[i]))
		{
			cur.first = prime[i];
			cur.second = 0;

			while (!(temp%prime[i]))
			{
				cur.second++;

				temp /= prime[i];
			}

			div.push_back(cur);
		}
	}

	if (temp != 1)
	{
		div.push_back(pair<long long, long long>(temp, 1));
	}

	temp = n / div[0].first;

	cnt = 0;

	while (temp)
	{
		cnt += temp;

		temp /= div[0].first;
	}

	min = cnt / div[0].second;

	for (i = 1; i < div.size(); i++)
	{
		temp = n / div[i].first;

		cnt = 0;

		while (temp)
		{
			cnt += temp;

			temp /= div[i].first;
		}
		
		if (cnt / div[i].second < min)
		{
			min = cnt / div[i].second;
		}
	}

	printf("%I64d\n", min);

	return 0;
}