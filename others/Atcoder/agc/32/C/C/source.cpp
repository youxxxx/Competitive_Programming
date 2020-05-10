#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<stack>

using namespace std;

vector<vector<int>> graph;

bool dfs(int source, int dest, int prev, int cur)
{
	int i;
	

	for (i = 0; i < graph[cur].size(); i++)
	{
		if (graph[cur][i] == prev)
		{
			continue;
		}

		if (graph[cur][i] == dest)
		{
			return false;
		}

		if (graph[cur][i] == source)
		{
			return true;
		}

		return dfs(source, dest, cur, graph[cur][i]);
	}
}

int main()
{
	int n, m;
	int deg[100001] = { 0, };
	int u, v;
	vector<pair<int, int>> arr;
	int res = 0;
	int f1 = -1, f2 = -1;
	int lmax = 0;
	vector<int> emp;
	bool valid=false;

	int i;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);

		arr.push_back(pair<int, int>(u, v));

		deg[u]++;
		deg[v]++;
	}
	
	for (i = 1; i <= n; i++)
	{
		if (deg[i] % 2)
		{
			printf("No\n");

			return 0;
		}

		res += deg[i] / 2 - 1;

		/*
		if (res > 2)
		{
			printf("No\n");

			return 0;
		}
		*/
	}

	if (res >= 3)
	{
		printf("Yes\n");
	}

	else if (res == 2)
	{
		for (i = 1; i <= n; i++)
		{
			if (deg[i] > lmax)
			{
				lmax = deg[i];
			}

			if (deg[i] == 4)
			{
				if (f1 == -1)
				{
					f1 = i;
				}

				else
				{
					f2 = i;
				}
			}
		}

		if (lmax == 6)
		{
			printf("Yes\n");
		}

		else
		{
			for (i = 0; i <= n; i++)
			{
				graph.push_back(emp);
			}

			for (i = 0; i < m; i++)
			{
				graph[arr[i].first].push_back(arr[i].second);
				graph[arr[i].second].push_back(arr[i].first);
			}

			for (i = 0; i < 4; i++)
			{
				valid = valid || dfs(f1, f2, f1, graph[f1][i]);
			}

			if (valid)
			{
				printf("Yes\n");
			}

			else
			{
				printf("No\n");
			}
		}
	}

	else
	{
		printf("No\n");
	}

	return 0;
}