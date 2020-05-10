#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int> graph[200001], subg[200001];
long long val[200001] = { 0, };
long long add[200001] = { 0, };

void dfs(int cur, int parent, long long addval)
{
	int next;
	int i;
	vector<int> ret, rvalue;

	addval += add[cur];

	val[cur] += addval;

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i];

		if (next == parent)
		{
			continue;
		}

		dfs(next, cur, addval);
	}
}

int main()
{
	int n, m;
	int i, j;
	int u, v;
	long long d;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (i = 0; i < m; i++)
	{
		scanf("%d %lld", &u, &d);

		add[u] += d;
	}

	dfs(1, 0, 0);

	for (i = 1; i <= n; i++)
	{
		printf("%lld ", val[i]);
	}

	return 0;
}
