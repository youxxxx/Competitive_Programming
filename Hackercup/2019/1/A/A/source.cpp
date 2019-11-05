#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool func(const pair<pair<int, int>, int > &a, const pair<pair<int, int>, int > &b)
{
	return a.second < b.second;
}

int main()
{
	int tc, t;
	int n, m;
	int dist[51][51];
	int constraint[51][51];
	vector<pair<int,int>> graph[51];
	vector<pair<pair<int, int>, int >> input;
	int x, y, z;
	int i, j, k;
	int u, v;
	int ud, vd;
	bool valid;

	freopen("graphs_as_a_service.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &tc);

	for (t = 0; t < tc; t++)
	{
		scanf("%d %d", &n, &m);

		for (i = 1; i <= 50; i++)
		{
			graph[i].clear();

			for (j = 1; j <= 50; j++)
			{
				dist[i][j] = -1;

				constraint[i][j] = -1;
			}
		}

		input.clear();

		for (i = 0; i < m; i++)
		{
			scanf("%d %d %d", &x, &y, &z);

			input.push_back(make_pair(make_pair(x, y), z));

			constraint[x][y] = constraint[y][x] = z;
		}

		sort(input.begin(), input.end(), func);

		valid = true;

		for (i = 0; i < m; i++)
		{
			x = input[i].first.first;
			y = input[i].first.second;
			z = input[i].second;

			if (dist[x][y] != -1 && dist[x][y] < z)
			{
				valid = false;

				break;
			}

			for (j = 0; j < graph[x].size(); j++)
			{
				u = graph[x][j].first;
				ud = dist[x][u];

				for (k = 0; k < graph[y].size(); k++)
				{
					v = graph[y][k].first;
					vd = dist[y][v];

					if (u == v)
					{
						continue;
					}

					if (constraint[u][v] != -1 && ud + vd + z < constraint[u][v])
					{
						valid = false;

						break;
					}

					if (dist[u][v] == -1)
					{
						graph[u].push_back(make_pair(v, dist[u][v]));
						graph[v].push_back(make_pair(u, dist[v][u]));
					}

					if (dist[u][v] == -1 || ud + vd + z < dist[u][v])
					{
						dist[u][v] = dist[v][u] = ud + vd + z;
					}
				}

				if (!valid)
				{
					break;
				}

				if (y == u)
				{
					continue;
				}

				if (constraint[y][u] != -1 && ud + z < constraint[y][u])
				{
					valid = false;

					break;
				}

				if (dist[y][u] == -1)
				{
					graph[y].push_back(make_pair(u, dist[y][u]));
					graph[u].push_back(make_pair(y, dist[u][y]));
				}

				if (dist[y][u] == -1 || ud + z < dist[y][u])
				{
					dist[y][u] = dist[u][y] = ud + z;
				}

			}

			if (!valid)
			{
				break;
			}

			for (j = 0; j < graph[y].size(); j++)
			{
				v = graph[y][j].first;
				vd = dist[y][v];

				if (x == v)
				{
					continue;
				}

				if (constraint[x][v] != -1 && vd + z < constraint[x][v])
				{
					valid = false;

					break;
				}

				if (dist[x][v] == -1)
				{
					graph[x].push_back(make_pair(v, dist[x][v]));
					graph[v].push_back(make_pair(x, dist[v][x]));
				}

				if (dist[x][v] == -1 || vd + z < dist[x][v])
				{
					dist[x][v] = dist[v][x] = vd + z;
				}
			}

			if (!valid)
			{
				break;
			}

			if (dist[x][y] == -1)
			{
				graph[x].push_back(make_pair(y, z));
				graph[y].push_back(make_pair(x, z));
			}

			dist[x][y] = dist[y][x] = z;
		}

		if (!valid)
		{
			printf("Case #%d: Impossible\n", t + 1);

			continue;
		}

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (constraint[i][j] != -1 && dist[i][j] < constraint[i][j])
				{
					valid = false;

					break;
				}
			}

			if (!valid)
			{
				break;
			}
		}

		if (!valid)
		{
			printf("Case #%d: Impossible\n", t + 1);

			continue;
		}

		printf("Case #%d: %d\n", t + 1, m);

		for (i = 0; i < m; i++)
		{
			printf("%d %d %d\n", input[i].first.first, input[i].first.second, input[i].second);
		}
	}

	return 0;
}