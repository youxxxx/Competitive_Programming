#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

vector<int> graph[200001];
int depth[200001];
bool visited[200001] = { 0, };
int ancestor[200001][21];

void dfs(int cur, int curdepth)
{
	depth[cur] = curdepth;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next;

		next = graph[cur][i];

		if (visited[next])
		{
			continue;
		}

		visited[next] = true;

		ancestor[next][0] = cur;

		dfs(next, curdepth + 1);
	}
}

int lca(int x, int y)
{
	if (depth[x] > depth[y])
	{
		int temp;

		temp = x;
		x = y;
		y = temp;
	}

	for (int i = 20; i >= 0; i--)
	{
		if (depth[y] - depth[x] >= (1 << i))
		{
			y = ancestor[y][i];
		}
	}

	if (x == y)
	{
		return x;
	}

	for (int i = 20; i >= 0; i--)
	{
		if (ancestor[x][i] != ancestor[y][i])
		{
			x = ancestor[x][i];
			y = ancestor[y][i];
		}
	}

	return ancestor[x][0];
}

int dist(int x, int y)
{
	int ansc;

	ansc = lca(x, y);

	return depth[x] - depth[ansc] + depth[y] - depth[ansc];
}

bool func(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second > b.second;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		graph[i].clear();
	}

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;

		scanf("%d %d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	visited[1] = true;
	dfs(1, 1);

	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ancestor[j][i] = ancestor[ancestor[j][i - 1]][i - 1];
		}
	}

	//depth[0] = 0;

	bool visited_v[200001];

	int visited_depth[200001];

	for (int i = 0; i <= n; i++)
	{
		visited_v[i] = false;
		visited_depth[i] = -1;
	}

	bool valid = true;

	for (int i = 0; i < m; i++)
	{
		int k;

		scanf("%d", &k);

		bool valid = true;

		vector<pair<int,int>> p;

		for (int j = 0; j < k; j++)
		{
			int v;

			scanf("%d", &v);

			if (valid)
			{
				if (!visited_v[ancestor[v][0]])
				{
					visited_v[ancestor[v][0]] = true;

					if (visited_depth[depth[ancestor[v][0]]] != -1)
					{
						valid = false;
					}

					visited_depth[depth[ancestor[v][0]]] = ancestor[v][0]; 

					p.push_back({ ancestor[v][0],depth[ancestor[v][0]] });
				}
			}
		}

		if (valid)
		{
			sort(p.begin(), p.end(), func);

			for (int i = 0; i < p.size() - 1; i++)
			{
				if (lca(p[i].first, p[i + 1].first)!=p[i + 1].first)
				{
					valid = false;

					break;
				}
			}
		}

		for (int i = 0; i < p.size(); i++)
		{
			visited_v[p[i].first] = false;
			visited_depth[depth[p[i].first]] = -1;
		}

		if (valid)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}