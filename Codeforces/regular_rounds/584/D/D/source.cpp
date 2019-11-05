#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

vector<int> graph[100001];
set<int> check[100001];
bool visited[100001] = { 0, };

int dfs(int cur, int parent)
{
	int i;
	int next;
	int ret, rvalue = 1;

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i];

		if (next == parent || visited[next])
		{
			continue;
		}

		visited[next] = true;

		ret = dfs(next, cur);

		rvalue += ret;
	}

	return rvalue;
}

int main()
{
	int n, m;
	int i;
	int sol = 0, left;
	int u, v;

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);

		if (check[u].count(v))
		{
			sol++;
		}

		else
		{
			check[u].insert(v);
			check[v].insert(u);

			graph[u].push_back(v);
			graph[v].push_back(u);
		}
	}

	left = m - sol;

	for (i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;

			left -= dfs(i, 0) - 1;
		}
	}

	sol += left;

	printf("%d\n", sol);

	return 0;
}