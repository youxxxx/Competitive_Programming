#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>
#include<queue>

using namespace std;

vector<int> graph[500001];
int parent[500001];
bool visited[500001];
int val[500001];

void dfs(int cur)
{
	int i;
	int next;

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i];

		if (next == parent[cur])
		{
			continue;
		}

		parent[next] = cur;

		dfs(next);
	}
}

int main()
{
	int tc, cases;
	int n, k;
	int i, j;
	queue<pair<int, int>> q;
	int u, v;
	int cnt;
	int next;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d %d", &n, &k);

		for (i = 1; i <= n; i++)
		{
			graph[i].clear();

			visited[i] = false;

			val[i] = 0;
		}

		for (i = 0; i < n - 1; i++)
		{
			scanf("%d %d", &u, &v);

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		parent[1] = 0;

		dfs(1);

		cnt = 0;

		for (i = 2; i <= n; i++)
		{
			if (graph[i].size() == 1)
			{
				if (k != 1)
				{
					q.push(make_pair(i, 1));
				}

				//visited[i] = true;

				cnt++;
			}
		}

		for (i = 2; i <= k; i++)
		{
			if (q.empty())
			{
				break;
			}

			while (!q.empty() && q.front().second == i - 1)
			{
				next = parent[q.front().first];

				if (next && ++val[next] == graph[next].size() - 1 + (next == 1))
				{
					//visited[next] = true;

					q.push(make_pair(next, i));

					cnt++;
				}

				q.pop();
			}
		}

		while (!q.empty())
		{
			q.pop();
		}

		printf("%d\n", cnt);
	}

	return 0;
}