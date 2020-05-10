#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

pair<int, int> sol[500001];
vector<int> graph[500001];
bool visited[500001] = { 0, };

int dfs(int cur, int start, int end)
{
	int add = 0;
	int cnt = 0;
	
	end += graph[cur].size() - 1 + (cur == 1);

	sol[cur] = { start, end };

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next;

		next = graph[cur][i];

		if (visited[next])
		{
			continue;
		}

		visited[next] = true;

		cnt++;

		add += dfs(next, end - cnt, end + add + cnt);
	}

	return add + cnt * 2;
}

int main()
{
	int n;
	
	//freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;

		scanf("%d %d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	visited[1] = true;

	dfs(1, 1, 2);

	for (int i = 1; i <= n; i++)
	{
		printf("%d %d\n", sol[i].first, sol[i].second);
	}

	return 0;
}