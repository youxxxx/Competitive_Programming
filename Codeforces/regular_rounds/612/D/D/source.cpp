#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;

int c[2001];
vector<int> graph[2001];
int parent[2001];
int weight[2001];
int color[2001];

bool skip[8000] = { 0, };

int dfs(int cur)
{
	int sum = 0;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next;

		next = graph[cur][i];

		if (next == parent[cur])
		{
			continue;
		}

		sum += dfs(next);
	}

	weight[cur] = sum + 1;

	return weight[cur];
}

void dfs2(int cur, int start)
{
	int sum = 0;
	int add = 0;
	int ptr;

	ptr = start + c[cur];

	while (skip[ptr])
	{
		ptr++;
	}

	color[cur] = ptr;

	skip[ptr] = true;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next;

		next = graph[cur][i];

		if (next == parent[cur])
		{
			continue;
		}

		dfs2(next, start + sum + add);

		sum += weight[next];

		if (sum  >= c[cur])
		{
			add = 1;
		}
	}
}

int main()
{
	int n;
	int root;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &parent[i], &c[i]);

		graph[parent[i]].push_back(i);

		if (parent[i] == 0)
		{
			root = i;
		}
	}

	dfs(root);

	for (int i = 1; i <= n; i++)
	{
		if (c[i] >= weight[i])
		{
			printf("NO\n");

			return 0;
		}
	}

	dfs2(root, 1);

	printf("YES\n");

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", color[i]);
	}

	return 0;
}