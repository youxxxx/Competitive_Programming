#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	long long n;
	long long arr[200001];

	scanf("%lld", &n);
	
	for (long long i = 1; i <= n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	long long add[200001] = { 0, };
	map<pair<long long, long long>, long long> list;
	long long q;

	scanf("%lld", &q);

	long long lmax[200001] = { 0, };
	long long cnt[200001] = { 0, };
	long long sum = 0;

	for (long long i = 1; i <= n; i++)
	{
		lmax[i] = arr[i];

		sum += arr[i];
	}

	for (long long i = 0; i < q; i++)
	{
		long long s, t, u;

		scanf("%lld %lld %lld", &s, &t, &u);

		map<pair<long long, long long>, long long>::iterator ret;

		ret = list.find({ s,t });

		if (ret == list.end() && u == 0 || ret != list.end() && ret->second == u)
		{
			printf("%lld\n", sum + !sum);

			continue;
		}

		if (ret == list.end() || ret->second == 0 && u != 0)
		{
			if (--lmax[u] >= 0)
			{
				sum--;
			}

			list[{s, t}] = u;
		}

		else if (u == 0)
		{
			if (++lmax[ret->second] >= 1)
			{
				sum++;
			}

			list[{s, t}] = u;
		}

		else
		{
			if (++lmax[ret->second] >= 1)
			{
				sum++;
			}

			if (--lmax[u] >= 0)
			{
				sum--;
			}

			list[{s, t}] = u;
		}

		printf("%lld\n", sum + !sum);
	}

	return 0;
}