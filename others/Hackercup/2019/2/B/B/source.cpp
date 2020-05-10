#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

//vector<int> graph[4001];

int root[4001];

int find(int x)
{
	if (root[x] == x)
	{
		return x;
	}
	else
	{
		return root[x] = find(root[x]);
	}
}

void union_find(int x, int y)
{
	x = find(x);
	y = find(y);

	root[y] = x;
}

int main()
{
	int t, tc;
	int n, m;
	int i, j;
	int x, y;
	int val;
	string sol;
	map<int, int> list;
	map<int, int>::iterator it, ret;
	int parity[4001];
	bool dp[4001][4001];
	int prev[4001][4001];
	int cur[4001][4001];
	int ptr, ptr2;
	vector<int> target;
	vector<pair<int, int>> arr;
	int ub;
	int preval;

	freopen("bitstrings_as_a_service.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &tc);

	for (t = 0; t < tc; t++)
	{
		scanf("%d %d", &n, &m);

		sol.clear();
		list.clear();
		target.clear();
		arr.clear();

		if (m == 0)
		{
			for (i = 0; i < n / 2; i++)
			{
				sol.push_back('0');
			}

			for (i = n / 2; i < n; i++)
			{
				sol.push_back('1');
			}

			printf("Case #%d: %s\n", t + 1, sol.c_str());

			continue;
		}

		for (i = 1; i <= n; i++)
		{
			//graph[i].clear();

			root[i] = i;
			parity[i] = 0;

			dp[0][i] = false;
			prev[0][i] = -1;
			cur[0][i] = -1;
			
			/*
			for (j = 1; j <= n; j++)
			{
				dp[i][j] = false;

				prev[i][j] = cur[i][j] = -1;
			}
			*/
		}

		for (i = 0; i <= n; i++)
		{
			dp[i][0] = true;
			prev[i][0] = -1;
			cur[i][0] = -1;
		}

		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &x, &y);

			for (j = x; j < (x + y) / 2 + (y - x) % 2; j++)
			{
				/*
				graph[j].push_back(y + x - j);
				graph[y + x - j].push_back(j);
				*/

				union_find(j, y + x - j);
			}
		}

		for (i = 1; i <= n; i++)
		{
			val = find(i);

			ret = list.find(val);

			if (ret == list.end())
			{
				list[val] = 1;
			}

			else
			{
				ret->second++;
			}
		}

		i = 1;
		
		arr.push_back(make_pair(0, 0));

		for (it = list.begin(); it != list.end(); it++)
		{
			val = it->second;

			for (j = 1; j <= n; j++)
			{
				dp[i][j] = dp[i - 1][j];
				prev[i][j] = prev[i - 1][j];
				cur[i][j] = cur[i - 1][j];

				if (val <= j)
				{
					if (!dp[i][j] && dp[i - 1][j - val])
					{
						dp[i][j] = true;
						prev[i][j] = cur[i - 1][j - val];
						cur[i][j] = i;
					}
				}
			}

			arr.push_back(make_pair(it->first, it->second));

			i++;
		}

		ub = i;

		for (i = n / 2; i >= 0; i--)
		{
			if (dp[ub - 1][i])
			{
				ptr = cur[ub - 1][i];
				ptr2 = i;

				while (ptr != -1)
				{
					target.insert(target.begin(), ptr);

					preval = arr[ptr].second;

					ptr = prev[ptr][ptr2];

					if (ptr == -1)
					{
						break;
					}

					ptr2 -= preval;
				}

				break;
			}
		}

		for (i = 0; i < target.size(); i++)
		{
			parity[arr[target[i]].first] = 1;
		}

		for (i = 1; i <= n; i++)
		{
			sol.push_back(parity[root[i]] + '0');
		}

		printf("Case #%d: %s\n", t + 1, sol.c_str());
	}

	return 0;
}