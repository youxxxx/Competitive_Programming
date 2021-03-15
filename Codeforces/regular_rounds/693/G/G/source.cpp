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

vector<int> graph[200001];
vector<int> rgraph[200001];
int dist[200001];
int rdist[200001];

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%lld %lld", &n, &m);

		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
			rgraph[i].clear();

			dist[i] = -1;
			rdist[i] = n + 1;
		}

		dist[1] = 0;

		for (int i = 0; i < m; i++)
		{
			int u, v;

			scanf("%d %d", &u, &v);

			graph[u].push_back(v);
			rgraph[v].push_back(u);
		}

		queue<pair<int, int>> q;

		q.push({ 1,0 });

		while (!q.empty())
		{
			const int cur = q.front().first;
			const int curdist = q.front().second;
			q.pop();

			for (int i = 0; i < (int)graph[cur].size(); i++)
			{
				const int next = graph[cur][i];

				if (dist[next] != -1)
				{
					continue;
				}

				dist[next] = curdist + 1;

				q.push({ next,curdist + 1 });
			}
		}

		priority_queue<pair<int, int>> pq;

		for (int i = 1; i <= n; i++)
		{
			pq.push({ -dist[i],i });
		}

		while (!pq.empty())
		{
			int curdist = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			if (curdist > rdist[cur])
			{
				continue;
			}

			for (int i = 0; i < (int)rgraph[cur].size(); i++)
			{
				const int next = rgraph[cur][i];

				if (dist[next] < dist[cur])
				{
					if (rdist[cur] < rdist[next])
					{
						rdist[next] = rdist[cur];

						pq.push({ -rdist[next],next });
					}

					/*
					if(min(rdist[cur], dist[cur]) < rdist[next])
					{
						rdist[next] = min(rdist[cur], dist[cur]);

						pq.push({ -rdist[next],next });
					}
					*/
				}

				else
				{
					if (dist[cur] < rdist[next])
					{
						rdist[next] = dist[cur];

						pq.push({ -rdist[next],next });
					}
				}
			}
		}

		for (int i = 1; i <= n; i++)
		{
			printf("%d ", min(dist[i], rdist[i]));
		}

		printf("\n");
	}

	return 0;
}