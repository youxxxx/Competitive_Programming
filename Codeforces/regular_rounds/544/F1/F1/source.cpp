#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
	vector<vector<int>> graph;
	vector<int> emp;
	vector<pair<int, int>> box;
	int n, m;
	int i, j;
	int u, v;
	bool visited[200001] = { false, };
	int *cnt;
	int midx;
	int lmax = -1;
	int cur, next;
	int edges = 0;
	stack<int> s;

	scanf("%d %d", &n, &m);

	cnt = new int[n + 1];

	for (i = 0; i <= n; i++)
	{
		graph.push_back(emp);

		cnt[i] = 0;
	}

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);

		cnt[u]++;
		cnt[v]++;
	}

	for (i = 1; i <= n; i++)
	{
		if (cnt[i] > lmax)
		{
			lmax = cnt[i];
			midx = i;
		}
	}

	visited[midx] = true;

	for (i = 0; i < graph[midx].size(); i++)
	{
		next = graph[midx][i];

		visited[next] = true;

		s.push(next);

		box.push_back(pair<int, int>(midx, next));

		edges++;
	}

	while (!s.empty() && edges < n - 1)
	{
		cur = s.top();
		s.pop();

		for (i = 0; i < graph[cur].size(); i++)
		{
			next = graph[cur][i];

			if (visited[next])
			{
				continue;
			}

			visited[next] = true;

			s.push(next);

			box.push_back(pair<int, int>(cur, next));

			edges++;
		}
	}

	for (i = 0; i < n - 1; i++)
	{
		printf("%d %d\n", box[i].first, box[i].second);
	}

	return 0;
}