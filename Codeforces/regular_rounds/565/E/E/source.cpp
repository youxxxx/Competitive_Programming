#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

vector<vector<int>> graph;
vector<int> sol[2];
bool visited[200001];

int main()
{
	int t, z;
	vector<int> emp;
	int n, m;
	int i, j;
	int u, v;
	int next;
	queue<pair<int,int>> q;
	pair<int,int> cur;
	int vertex, phase;
	int idx;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &m);

		graph.clear();
		sol[0].clear();
		sol[1].clear();

		for (i = 0; i <= n; i++)
		{
			graph.push_back(emp);

			visited[i] = false;
		}

		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &u, &v);

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		sol[0].push_back(1);
		visited[1] = true;

		for (i = 0; i < graph[1].size(); i++)
		{
			next = graph[1][i];
			q.push(pair<int,int>(next, 1));

			sol[1].push_back(next);

			visited[next] = true;
		}

		while (!q.empty())
		{
			cur = q.front();
			q.pop();

			vertex = cur.first;
			phase = cur.second;

			for (i = 0; i < graph[vertex].size(); i++)
			{
				next = graph[vertex][i];

				if (!visited[next])
				{
					q.push(pair<int, int>(next, !phase));

					sol[!phase].push_back(next);

					visited[next] = true;
				}
			}
		}

		if (sol[0].size() <= n / 2)
		{
			idx = 0;
		}

		else
		{
			idx = 1;
		}

		printf("%d\n", sol[idx].size());

		for (i = 0; i < sol[idx].size(); i++)
		{
			printf("%d ", sol[idx][i]);
		}

		printf("\n");
	}

	return 0;
}