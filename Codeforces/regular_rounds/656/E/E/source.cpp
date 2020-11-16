#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

vector<int> graph[200001];
bool visited[200001];
bool rec[200001];

bool dfs(int cur)
{
	rec[cur] = true;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		const int next = graph[cur][i];

		if (visited[next])
		{
			if (rec[next])
			{
				return false;
			}

			continue;
		}

		visited[next] = true;

		const int ret = dfs(next);

		if (!ret)
		{
			return false;
		}
	}

	rec[cur] = false;

	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		int in[200001];
		bool preset[200001];

		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();

			visited[i] = false;

			in[i] = 0;

			preset[i] = false;

			rec[i] = false;
		}

		vector<pair<int, int>> add;

		for (int i = 0; i < m; i++)
		{
			int t, u, v;

			scanf("%d %d %d", &t, &u, &v);

			if (t)
			{
				graph[u].push_back(v);

				in[v]++;

				preset[u] = preset[v] = true;
			}

			else
			{
				add.push_back({ u,v });
			}
		}

		visited[1] = true;

		if (!dfs(1))
		{
			printf("NO\n");

			continue;
		}

		printf("YES\n");

		queue<int> q;
		int val[200001];

		for (int i = 1; i <= n; i++)
		{
			if (!in[i])
			{
				q.push(i);
			}
		}

		int cnt = 0;

		while (!q.empty())
		{
			const int cur = q.front();

			q.pop();

			val[cur] = cnt++;

			for (int i = 0; i < graph[cur].size(); i++)
			{
				const int next = graph[cur][i];

				if (!(--in[next]))
				{
					q.push(next);
				}
			}
		}

		for (int i = 0; i < add.size(); i++)
		{
			const int u = add[i].first;
			const int v = add[i].second;

			if (!preset[u] && !preset[v])
			{
				if (u < v)
				{
					printf("%d %d\n", u, v);
				}

				else
				{
					printf("%d %d\n", v, u);
				}
			}

			else if (!preset[u])
			{
				printf("%d %d\n", u, v);
			}

			else if (!preset[v])
			{
				printf("%d %d\n", v, u);
			}

			else
			{
				if (val[u] < val[v])
				{
					printf("%d %d\n", u, v);
				}

				else
				{
					printf("%d %d\n", v, u);
				}
			}
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < graph[i].size(); j++)
			{
				printf("%d %d\n", i, graph[i][j]);
			}
		}
	}

	return 0;
}