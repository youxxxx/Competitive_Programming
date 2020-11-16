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

vector<int> graph[100001];
int num[100001];
int tot[100001];
int good[100001];
int bad[100001];
int val[100001];

int dfs(int cur, int parent)
{
	tot[cur] = num[cur];

	for (int i = 0; i < graph[cur].size(); i++)
	{
		const int next = graph[cur][i];

		if (next == parent)
		{
			continue;
		}

		const int ret = dfs(next, cur);

		if (ret == -1)
		{
			return -1;
		}

		tot[cur] += ret;
	}

	if (abs(val[cur]) > tot[cur] || (tot[cur] + val[cur]) % 2)
	{
		return -1;
	}

	good[cur] = (tot[cur] + val[cur]) / 2;
	bad[cur] = tot[cur] - good[cur];

	return tot[cur];
}

bool dfs2(int cur, int parent)
{
	int sum = 0;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		const int next = graph[cur][i];

		if (next == parent)
		{
			continue;
		}

		if (!dfs2(next, cur))
		{
			return false;
		}

		sum += good[next];
	}

	if (sum > good[cur])
	{
		return false;
	}

	return true;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
			num[i] = 0;
			tot[i] = 0;
			good[i] = 0;
			bad[i] = 0;
		}

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
		}

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &val[i]);
		}

		for (int i = 0; i < n - 1; i++)
		{
			int u, v;

			scanf("%d %d", &u, &v);

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		const int ret = dfs(1, 0);

		if (ret == -1)
		{
			printf("NO\n");

			continue;
		}

		if (!dfs2(1, 0))
		{
			printf("NO\n");

			continue;
		}

		printf("YES\n");
	}

	return 0;
}