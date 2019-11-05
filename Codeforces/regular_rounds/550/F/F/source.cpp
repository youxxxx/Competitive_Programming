#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
int *vcolor;
int *ecolor;
vector<vector<pair<int, pair<int, int>>>> graph;

bool dfs(int cur, int parent, int color)
{
	int i;
	int next;
	int st;

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i].first;

		if (next == parent)
		{
			continue;
		}

		if (vcolor[next] == color)
		{
			return false;
		}

		st = graph[cur][i].second.first;
		ecolor[graph[cur][i].second.second] = ((color && st) || (!color&&!st));

		if (vcolor[next] == -1)
		{
			vcolor[next] = !color;

			if (!dfs(next, cur, !color))
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int n, m;
	int u, v;
	vector<pair<int, pair<int, int>>> emp;
	int i, j;
	int st;

	scanf("%d %d", &n, &m);

	vcolor = new int[n + 1];
	ecolor = new int[m];

	for (i = 0; i <= n; i++)
	{
		graph.push_back(emp);

		vcolor[i] = -1;
	}

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);

		graph[u].push_back(pair<int, pair<int, int>>(v, pair<int, int>(0, i)));
		graph[v].push_back(pair<int, pair<int, int>>(u, pair<int, int>(1, i)));
	}

	vcolor[1] = 0;

	if (!dfs(1, 0, 0))
	{
		printf("NO\n");
	}

	else
	{
		printf("YES\n");

		for (i = 0; i < m; i++)
		{
			printf("%d", ecolor[i]);
		}
	}

	return 0;
}