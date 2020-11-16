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

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	vector<pair<int,int>> graph[1001];
	pair<pair<int, int>,int> edge[1001];

	int dist[1001][1001];

	memset(dist, -1, sizeof(dist));

	for (int i = 0; i < m; i++)
	{
		int u, v, d;

		scanf("%d %d %d", &u, &v, &d);

		graph[u].push_back({ v,d });
		graph[v].push_back({ u,d });

		dist[u][v] = dist[v][u] = d;

		edge[i] = { {u,v},d };
	}

	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;

		priority_queue<pair<int, int>> pq;

		for (int j = 0; j < graph[i].size(); j++)
		{
			pq.push({ -graph[i][j].second,graph[i][j].first });
		}

		while (!pq.empty())
		{
			const int curdist = -pq.top().first;
			const int v = pq.top().second;
			pq.pop();

			if (dist[i][v] != -1 && dist[i][v] < curdist)
			{
				continue;
			}

			for (int j = 0; j < graph[v].size(); j++)
			{
				const int next = graph[v][j].first;
				const int nextdist = graph[v][j].second;

				if (dist[i][next] == -1 || curdist + nextdist < dist[i][next])
				{
					dist[i][next] = curdist + nextdist;

					pq.push({ -(curdist + nextdist),next });
				}
			}
		}
	}

	pair<int, int> courier[1001];

	int sol = 0;

	for (int i = 0; i < k; i++)
	{
		int u, v;

		scanf("%d %d", &u, &v);

		courier[i] = { u,v };

		sol += dist[u][v];
	}

	for (int i = 0; i < m; i++)
	{
		int cand = 0;

		const int x = edge[i].first.first;
		const int y = edge[i].first.second;

		for (int j = 0; j < k; j++)
		{
			const int u = courier[j].first;
			const int v = courier[j].second;

			cand += min(dist[u][v], min(dist[u][x] + dist[y][v], dist[u][y] + dist[x][v]));
		}

		sol = min(sol, cand);
	}

	printf("%d\n", sol);

	return 0;
}