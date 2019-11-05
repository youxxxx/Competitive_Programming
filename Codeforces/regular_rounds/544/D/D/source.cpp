#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

long long gcd(long long a, long long b)
{
	long long temp;

	while (b)
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
	int n;
	vector<long long> a, b;
	long long input;
	int i;
	long long div;
	pair<long long, long long> cur;
	map<pair<long long, long long>, long long> tot;
	map<pair<long long, long long>, long long>::iterator it, ret;
	int lmax = 0;
	int bonus = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		a.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		b.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			if (b[i] != 0)
			{
				continue;
			}

			else
			{
				bonus++;

				continue;
			}
		}

		if (b[i] == 0)
		{
			lmax++;

			continue;
		}

		div = gcd(a[i], b[i]);

		cur.first = a[i] / div;
		cur.second = b[i] / div;

		ret = tot.find(cur);

		if (ret == tot.end())
		{
			tot[cur] = 1;
		}

		else
		{
			ret->second++;
		}
	}

	for (it = tot.begin(); it != tot.end(); it++)
	{
		if (it->second > lmax)
		{
			lmax = it->second;
		}
	}

	printf("%d\n", lmax + bonus);

	return 0;
}