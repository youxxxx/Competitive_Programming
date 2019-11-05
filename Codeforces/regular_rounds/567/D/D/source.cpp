#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

#define MOD 1000000007

using namespace std;

bool func(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.first < b.first;
}

bool func2(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.second < b.second;
}

int main()
{
	long long n, m, q;
	long long arr[500001] = { 0, };
	map<long long, vector<long long>> list;
	map<long long, vector<long long>>::iterator it, ret, it2;
	vector<long long> emp, rot, base;
	vector<long long>::iterator ptr, lb;
	vector<pair<long long, long long>> query, sol;
	long long i, j;
	long long input;
	long long cur, next, acc;
	long long height;

	//freopen("input.txt", "r", stdin);

	scanf("%lld %lld %lld", &n, &m, &q);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		base.push_back(input);

		arr[input]++;
	}

	for (i = 1; i <= m; i++)
	{
		ret = list.find(arr[i]);

		if (ret == list.end())
		{
			list[arr[i]] = emp;

			list[arr[i]].push_back(i);
		}

		else
		{
			ret->second.push_back(i);
		}
	}

	for (i = 0; i < q; i++)
	{
		scanf("%lld", &input);

		query.push_back(make_pair(input, i));
	}

	sort(query.begin(), query.end(), func);

	if (list.size() == 1)
	{
		for (i = 0; i < q; i++)
		{
			if (query[i].first <= n)
			{
				sol.push_back(make_pair(base[query[i].first - 1], query[i].second));
			}

			else
			{
				sol.push_back(make_pair((query[i].first - n - 1) % m + 1, query[i].second));
			}
		}
	}

	else
	{
		cur = n;
		it2 = it = list.begin();
		it2++;
		next = n + it->second.size() * (it2->first - it->first);
		height = it->first;
		acc = it->second.size();

		for (j = 0; j < it->second.size(); j++)
		{
			rot.push_back(it->second[j]);
		}

		for (i = 0; i < q; i++)
		{
			if (query[i].first <= n)
			{
				sol.push_back(make_pair(base[query[i].first - 1], query[i].second));

				continue;
			}

			it2 = it;

			if (it2 != list.end())
			{
				it2++;
			}

			if (it2 != list.end())
			{
				while (next < query[i].first && ++it != list.end() && ++it2 != list.end())
				{
					acc += it->second.size();

					cur = next;

					next += acc*(it2->first - it->first);

					height = it->first;

					lb = rot.begin();

					for (j = 0; j < it->second.size(); j++)
					{
						ptr = lower_bound(lb, rot.end(), it->second[j]);

						lb = rot.insert(ptr, it->second[j]);
					}
				}
			}

			if (next < query[i].first)
			{
				cur = next;

				it = list.end();
			}

			if (it == list.end()) 
			{
				sol.push_back(make_pair((query[i].first - cur - 1) % m + 1, query[i].second));
			}

			else
			{
				sol.push_back(make_pair(rot[(query[i].first - cur - 1) % rot.size()], query[i].second));
			}
		}
	}

	sort(sol.begin(), sol.end(), func2);

	for (i = 0; i < q; i++)
	{
		printf("%lld\n", sol[i].first);
	}

	return 0;
}