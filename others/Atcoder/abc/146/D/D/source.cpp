#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int>> graph[100001];
int curmax = 0;
int color[100001];

void dfs(int cur, int parent, int prev_color)
{
	int cnt = 0;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next;

		next = graph[cur][i].first;

		if (next == parent)
		{
			continue;
		}

		int next_color;

		next_color = (prev_color + cnt + 1) % curmax;

		color[graph[cur][i].second] = next_color + 1;

		dfs(next, cur, next_color);

		cnt++;
	}
}

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;

		scanf("%d %d", &u, &v);

		graph[u].push_back(make_pair(v, i));
		graph[v].push_back(make_pair(u, i));
	}

	for (int i = 1; i <= n; i++)
	{
		if (graph[i].size() > curmax)
		{
			curmax = graph[i].size();
		}
	}

	dfs(1, 0, -1);

	printf("%d\n", curmax);

	for (int i = 0; i < n - 1; i++)
	{
		printf("%d\n", color[i]);
	}

	return 0;
}