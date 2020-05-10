#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

#define MAX 999999999999999999

using namespace std;

vector<int> graph[2501];
vector<pair<pair<int, int>, long long>> arr;
long long adj[2501][2501];
int parent[2501];
bool reachable[2501] = { 0, };
bool inf[2501] = { false, };

void dfs(int cur)
{
	int i;
	int next;

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i];

		if (!inf[next])
		{
			inf[next] = true;

			dfs(next);
		}
	}
}

void dfs2(int cur)
{
	int i;
	int next;

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i];

		if (!reachable[next])
		{
			reachable[next] = true;

			dfs2(next);
		}
	}
}

int main()
{
	int n, m;
	int u, v;
	long long d, p;
	int i, j;
	long long dist[2501];
	bool changed;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d %lld", &n, &m, &p);

	for (i = 2; i <= n; i++)
	{
		dist[i] = MAX;
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			adj[i][j] = MAX;
		}

		adj[i][i] = 0;
	}

	dist[1] = 0;
	reachable[1] = true;

	for (i = 0; i < m; i++)
	{
		scanf("%d %d %lld", &u, &v, &d);

		if (u == v)
		{
			if (p - d < 0)
			{
				adj[u][v] = p - d;

				inf[u] = true;
			}
		}

		else
		{
			adj[u][v] = p - d;

			arr.push_back(make_pair(make_pair(u, v), p - d));

			graph[u].push_back(v);
		}
	}

	dfs2(1);

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < arr.size(); j++)
		{
			if (dist[arr[j].first.first] + arr[j].second < dist[arr[j].first.second])
			{
				dist[arr[j].first.second] = dist[arr[j].first.first] + arr[j].second;
			}
		}
	}

	for (i = 0; i < arr.size(); i++)
	{
		if (dist[arr[i].first.first] != MAX&&dist[arr[i].first.first] + arr[i].second < dist[arr[i].first.second])
		{
			inf[arr[i].first.first] = true;
		}
	}

	for (i = 1; i <= n; i++)
	{
		if (inf[i] && reachable[i])
		{
			dfs(i);
		}
	}

	if (inf[n])
	{
		printf("-1\n");
	}

	else
	{
		printf("%lld\n", -dist[n] > 0 ? -dist[n] : 0);
	}

	/*
	changed = true;
	while (changed)
	{
	for (i = 1; i <= n; i++)
	{
	for (j = 1; j <= n; j++)
	{
	if (dist[j] > dist[i] + adj[i][j])
	{
	dist[j] = dist[i] + adj[i][j];

	changed = true;
	}
	}
	}
	}
	*/

	return 0;
}