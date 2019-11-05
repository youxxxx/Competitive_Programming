#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

bool func(const pair<int, long long> &a, const pair<int, long long> &b)
{
	return a.second < b.second;
}

int main()
{
	int t, z;
	int n, q;
	int i, j;
	vector<pair<int, long long>> cost;
	vector<long long> org;
	vector<pair<int, int>> range;
	vector<int> buf;
	int *pos;
	long long input;
	int prev, preidx;
	int u, v, temp;
	long long sol;

	scanf("%d", &t);

	pos = new int[200001];

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &q);

		cost.clear();
		range.clear();
		org.clear();

		org.push_back(0);

		for (i = 1; i <= n; i++)
		{
			scanf("%lld", &input);

			cost.push_back(pair<int, long long>(i, input));

			org.push_back(input);
		}

		sort(cost.begin(), cost.end(), func);

		prev = -1;
		preidx = 0;

		for (i = 0; i < n; i++)
		{
			if (cost[i].second != prev)
			{
				if (prev != -1)
				{
					for (j = 0; j < buf.size(); j++)
					{
						pos[buf[j]] = range.size();
					}

					buf.clear();

					range.push_back(pair<int, int>(preidx, i));
				}

				prev = cost[i].second;
				preidx = i;
			}

			buf.push_back(cost[i].first);
		}

		for (j = 0; j < buf.size(); j++)
		{
			pos[buf[j]] = range.size();
		}

		buf.clear();

		range.push_back(pair<int, int>(preidx, i));

		for (i = 0; i < q; i++)
		{
			scanf("%d %d", &u, &v);

			if (u == v)
			{
				printf("0 1\n");

				continue;
			}

			sol = (long long)(v - u) + abs(org[v] - org[u]);

			if (pos[u] > pos[v])
			{
				temp = u;
				u = v;
				v = temp;
			}

			printf("%lld %d\n", sol, range[pos[v]].second - range[pos[u]].first);
		}
	}

	return 0;
}