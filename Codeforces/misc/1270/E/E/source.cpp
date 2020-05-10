#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int group[1001];

int uf(int a)
{
	if (a == group[a])
	{
		return a;
	}

	else return group[a] = uf(group[a]);
}

void disj(int a, int b)
{
	int next;
	int rvalue;
	int ar, br;

	ar = uf(a);
	br = uf(b);

	group[br] = ar;
}

int main()
{
	long long n;
	vector<pair<long long, long long>> arr;
	map<long long, vector<pair<long long,long long>>> dlist;
	long long pdist[1001][1001];

	scanf("%lld", &n);

	for (long long i = 0; i < n; i++)
	{
		long long x, y;

		scanf("%lld %lld", &x, &y);

		arr.push_back({ x,y });

		group[i] = i;
	}

	long long ptr = 1;

	for (long long i = 0; i < n; i++)
	{
		map<long long, long long> curlist;

		for (long long j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}

			map<long long, vector<pair<long long, long long>>>::iterator ret2;
			vector<pair<long long, long long>> emp;

			long long dist;

			dist = (arr[i].first - arr[j].first)*(arr[i].first - arr[j].first) + (arr[i].second - arr[j].second)*(arr[i].second - arr[j].second);

			pdist[i][j] = dist;

			if (i < j)
			{
				ret2 = dlist.find(dist);

				if (ret2 == dlist.end())
				{
					dlist[dist] = emp;

					dlist[dist].push_back({ i,j });
				}

				else
				{
					ret2->second.push_back({ i,j });
				}
			}

			map<long long, long long>::iterator ret;

			ret = curlist.find(dist);

			if (ret == curlist.end())
			{
				curlist[dist] = j;
			}

			else
			{
				long long u, v, temp;

				u = j;
				v = ret->second;

				if (uf(group[u]) > uf(group[v]))
				{
					temp = u;
					u = v;
					v = temp;
				}

				disj(u, v);

				ret->second = group[u];
			}
		}
	}

	map<long long, vector<pair<long long, long long>>>::iterator it;

	bool different[1001][1001] = { 0, };

	for (int z = 0; z < 2; z++)
	{
		for (it = dlist.begin(); it != dlist.end(); it++)
		{
			bool same = false;

			for (long long i = 0; i < it->second.size(); i++)
			{
				long long u, v;

				u = it->second[i].first;
				v = it->second[i].second;

				if (group[u] == group[v])
				{
					same = true;

					break;
				}
			}

			if (same)
			{
				for (long long i = 0; i < it->second.size(); i++)
				{
					long long u, v, temp;

					u = it->second[i].first;
					v = it->second[i].second;

					if (uf(group[u]) > uf(group[v]))
					{
						temp = u;
						u = v;
						v = temp;
					}

					disj(u, v);
				}
			}

			else if (z == 1)
			{
				for (long long i = 0; i < it->second.size(); i++)
				{
					different[it->second[i].first][it->second[i].second] = different[it->second[i].second][it->second[i].first] = true;
				}
			}
		}
	}

	for (it = dlist.begin(); it != dlist.end(); it++)
	{
		bool same = false;

		for (long long i = 0; i < it->second.size(); i++)
		{
			long long u, v;

			u = it->second[i].first;
			v = it->second[i].second;

			if (group[u] == group[v])
			{
				same = true;

				break;
			}
		}

		if (same)
		{
		}

		else
		{
			for (long long i = 0; i < it->second.size(); i++)
			{
				long long u, v, temp;

				u = it->second[i].first;
				v = it->second[i].second;

				if (group[u] == 0 || group[v] == 0)
				{
					continue;
				}

				disj(0, u);
			}
		}
	}

	/*
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (different[i][j])
			{
				if (group[i] == 0 || group[j] == 0)
				{
					continue;
				}

				if (different[0][i])
				{
					disj(0, j);
				}

				else
				{
					disj(0, i);
				}
			}
		}
	}
	*/

	vector<long long> sol;

	sol.push_back(1);

	for (long long i = 1; i < n; i++)
	{
		if (group[i] == 0)
		{
			sol.push_back(i + 1);
		}
	}

	printf("%d\n", sol.size());

	for (long long i = 0; i < sol.size(); i++)
	{
		printf("%lld ", sol[i]);
	}

	return 0;
}