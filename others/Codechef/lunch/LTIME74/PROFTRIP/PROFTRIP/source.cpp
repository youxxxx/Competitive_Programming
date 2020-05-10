#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

long long dist[301][301], lmin[301][301], cost[301], mincost[301];
bool visited[301][301];
vector<pair<long long, long long>> graph[301][301];
vector<pair<long long, long long>> road[301];

class comp
{
public:
	bool operator() (const pair<long long, long long> &a, const pair<long long, long long> &b) const
	{
		return a.first > b.first || a.first == b.first&&a.second < b.second;
	}
};

int main()
{
	long long cases, tc;
	long long i, j, k, l;
	long long input;
	long long cur;
	long long n, m;
	long long u, v;
	long long d;
	long long sol;
	priority_queue < pair<long long, long long>, vector<pair<long long, long long>>, comp> pq;

	//freopen("input.txt", "r", stdin);

	scanf("%lld", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%lld %lld", &n, &m);

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				dist[i][j] = -1;

				graph[i][j].clear();

				lmin[i][j] = -1;

				visited[i][j] = false;

				mincost[i] = -1;
			}

			road[i].clear();
		}

		for (i = 0; i < m; i++)
		{
			scanf("%lld %lld %lld", &u, &v, &d);

			dist[u][v] = dist[v][u] = d;

			road[u].push_back(pair<long long, long long>(v, d));
			road[v].push_back(pair<long long, long long>(u, d));
		}

		for (i = 1; i <= n; i++)
		{
			scanf("%lld", &cost[i]);
		}

		/*
		for (i = 1; i <= n; i++)
		{
		for (j = 1; j <= n; j++)
		{
		if (dist[i][j] != -1)
		{
		lmin[i][j] = lmin[j][i] = cost[i] < cost[j] ? cost[i] : cost[j];
		}
		}
		}
		*/

		/*
		for (i = 1; i <= n; i++)
		{
		for (j = 1; j <= n; j++)
		{
		if (i == j)
		{
		continue;
		}

		for (l = 0; l <= n; l++)
		{
		if (l == i || l == j)
		{
		continue;
		}

		if (dist[j][i] != -1 && dist[i][l] != -1 && (dist[j][l] == -1 || dist[j][i] + dist[i][l] < dist[j][l]))
		{
		dist[j][l] = dist[l][j] = dist[j][i] + dist[i][l];
		}

		lmin[j][l] = lmin[l][j] = lmin[j][i] < lmin[i][l] ? lmin[j][i] : lmin[i][l];
		}
		}
		}
		*/

		scanf("%lld %lld", &u, &v);

		visited[u][u] = true;
		lmin[u][u] = 0;

		pq.push(make_pair(u, u));

		while (!pq.empty())
		{
			long long i, j;
			pair<long long, long long> next, cur;
			long long node, curmin, nextnode, nextmin;

			cur = pq.top();

			pq.pop();

			node = cur.first;
			curmin = cur.second;

			for (i = 0; i < road[node].size(); i++)
			{
				next = road[node][i];
				nextnode = next.first;

				nextmin = cost[curmin] < cost[next.first] ? curmin : next.first;

				if (mincost[nextnode] == -1 || cost[mincost[nextnode]] > cost[nextmin] || lmin[nextnode][mincost[nextnode]] > lmin[node][curmin] + cost[curmin] * next.second)
				{
					if (mincost[nextnode] == -1 || cost[mincost[nextnode]] > cost[nextmin])
					{
						mincost[nextnode] = nextmin;
					}

					if (lmin[nextnode][nextmin] == -1 || lmin[node][curmin] + cost[curmin] * next.second < lmin[nextnode][nextmin])
					{
						lmin[nextnode][nextmin] = lmin[node][curmin] + cost[curmin] * next.second;

						if (nextnode != v)
						{
							pq.push(make_pair(nextnode, nextmin));
						}
					}
				}
			}
		}


		sol = 9000000000000000000;

		for (i = 1; i <= n; i++)
		{
			if (lmin[v][i] != -1 && lmin[v][i] < sol)
			{
				sol = lmin[v][i];
			}
		}

		printf("%lld\n", sol);
	}

	return 0;
}