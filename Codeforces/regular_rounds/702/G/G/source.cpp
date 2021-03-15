#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

bool func(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.first < b.first;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		long long arr[200001];

		scanf("%lld", &arr[0]);

		for (int i = 1; i < n; i++)
		{
			long long input;

			scanf("%lld", &input);

			arr[i] = arr[i - 1] + input;
		}

		long long MOD = arr[n - 1];

		if (MOD <= 0)
		{
			vector<pair<long long, long long>> list;

			list.push_back({ arr[0],0 });

			for (int i = 1; i < n; i++)
			{
				if (arr[i] > list.back().first)
				{
					list.push_back({ arr[i],i });
				}
			}

			for (int i = 0; i < m; i++)
			{
				long long query;

				scanf("%lld", &query);

				vector<pair<long long, long long>>::iterator ret = lower_bound(list.begin(), list.end(), pair<long long, long long>(query, 0), func);

				if (ret == list.end())
				{
					printf("-1 ");

					continue;
				}

				printf("%lld ", ret->second);
			}

			printf("\n");

			continue;
		}

		/*
		long long query[200001];

		for (int i = 0; i < m; i++)
		{
			scanf("%lld", &query[i]);
			if (MOD < 0)
			{
				query[i] *= -1;
			}
		}

		if (MOD < 0)
		{
			for (int i = 0; i < n; i++)
			{
				arr[i] *= -1;
			}

			MOD *= -1;
		}

		map<long long, vector<long long>> list;
		map<long long, long long> list2;

		for (int i = 0; i < n; i++)
		{
			vector<long long> emp;

			const long long r = (arr[i] % MOD + MOD) % MOD;

			const map<long long, long long>::iterator ret2 = list2.find(arr[i]);

			if (ret2 == list2.end())
			{
				list2[arr[i]] = i;

				map<long long, vector<long long>>::iterator ret = list.find(r);

				if (ret == list.end())
				{
					ret = list.insert({ r,emp }).first;
				}

				ret->second.push_back(arr[i]);
			}
		}

		for (map<long long, vector<long long>>::iterator it = list.begin(); it != list.end(); it++)
		{
			sort(it->second.begin(), it->second.end());
		}

		for (int i = 0; i < m; i++)
		{
			const long long r = (query[i] % MOD + MOD) % MOD;

			map<long long, vector<long long>>::iterator ret = list.find(r);

			if (ret == list.end())
			{
				printf("-1 ");

				continue;
			}

			vector<long long>::iterator ret2 = upper_bound(ret->second.begin(), ret->second.end(), query[i]);

			if (ret2 == ret->second.begin())
			{
				printf("-1 ");

				continue;
			}

			ret2--;

			printf("%lld ", list2[*ret2] + (query[i] - *ret2)/MOD*(long long)n);
		}
		*/

		vector<pair<long long, long long>> list;

		list.push_back({ arr[0],0 });

		for (int i = 1; i < n; i++)
		{
			if (arr[i] > list.back().first)
			{
				list.push_back({ arr[i],i });
			}
		}

		for (int i = 0; i < m; i++)
		{
			long long query;

			scanf("%lld", &query);

			vector<pair<long long, long long>>::iterator ret = lower_bound(list.begin(), list.end(), pair<long long, long long>(query, 0), func);

			if (ret != list.end())
			{
				printf("%lld ", ret->second);

				continue;
			}

			const long long q = (query - list.back().first + MOD - 1) / MOD;

			query -= q*MOD;

			ret = lower_bound(list.begin(), list.end(), pair<long long, long long>(query, 0), func);

			printf("%lld ", q*(long long)n + ret->second);
		}

		printf("\n");
	}

	return 0;
}