#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

bool odd[100001] = { 0, };
vector<int> graph[100001];
bool visited[100001] = { 0, };
map<pair<int, int>, int> list;
map<pair<int, int>, int>::iterator it, ret;

bool dfs(int cur, int parent)
{
	bool phase, rval;
	int i;
	int next;

	phase = odd[cur];

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i];

		if (visited[next])
		{
			continue;
		}

		if (next == parent)
		{
			continue;
		}

		visited[next] = true;

		rval = dfs(next, cur);

		phase = phase && !rval || !phase&&rval;
	}

	if (phase && parent)
	{
		ret = list.find(make_pair(cur, parent));

		if (ret == list.end())
		{
			ret = list.find(make_pair(parent, cur));

			ret->second = !ret->second;
		}

		else
		{
			ret->second = !ret->second;
		}
	}

	return phase;
}

int main()
{
	int n, m;
	int i, j;
	int u, v;
	bool tot = false;

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);

		odd[u] = !odd[u];

		list[make_pair(u, v)] = 0;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (i = 1; i <= n; i++)
	{
		tot = tot && !odd[i] || !tot&&odd[i];
	}

	if (tot)
	{
		printf("-1\n");

		return 0;
	}

	visited[1] = true;

	dfs(1, 0);

	for (it = list.begin(); it != list.end(); it++)
	{
		if (!it->second)
		{
			printf("%d %d\n", it->first.first, it->first.second);
		}

		else
		{
			printf("%d %d\n", it->first.second, it->first.first);
		}
	}

	return 0;
}