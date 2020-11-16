#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		a %= b;

		int temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	freopen("input.txt", "r", stdin);

	vector<int> prime;

	prime.push_back(2);

	for (int i = 3; i <= 2000; i += 2)
	{
		bool isprime = true;

		for (int j = 0; j < prime.size() && prime[j] * prime[j] <= i; j++)
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

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, k;
		int cnt[26] = { 0, };

		scanf("%d %d", &n, &k);

		char input[2001];

		scanf("%s", &input);

		string str = input;

		for (int i = 0; i < n; i++)
		{
			cnt[str[i] - 'a']++;
		}

		int lmax = 0;

		for (int i = 1; i <= n && i <= k; i++)
		{
			if (!(k % i))
			{
				lmax = i;
			}
		}

		for (int i = 1; i <= n && i <= k; i++)
		{
			int sum = 0;

			for (int j = 0; j < 26; j++)
			{
				sum += cnt[j] / i;
			}

			for (int j = 0; j < prime.size(); j++)
			{
				if (k % prime[j])
				{
					continue;
				}

				const int cand = sum / prime[j] * prime[j];

				if (cand > lmax)
				{
					lmax = cand;
				}
			}
		}

		/*
		for (int i = 2; i <= n; i++)
		{
			int sum = 0;

			for (int j = 0; j < 26; j++)
			{
				sum += cnt[j] / i;
			}

			const int cand = sum / k * k * i;

			if (cand > lmax)
			{
				lmax = cand;
			}
		}
		*/

		printf("%d\n", lmax);
	}

	return 0;
}