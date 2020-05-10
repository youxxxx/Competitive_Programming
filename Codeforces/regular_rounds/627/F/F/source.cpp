#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<cstring>
#include<map>
#include<set>
#include<stack>

using namespace std;

int color[200001];
vector<int> graph[200001];
vector<int> subtree[200001];
int lmax[200001];
bool visited[200001] = { false };
bool visited2[200001] = { false };

int dfs(int cur)
{
	int sum;

	sum = color[cur];

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next;

		next = graph[cur][i];

		subtree[cur].push_back(0);

		if (!visited[next])
		{
			int ret;

			visited[next] = true;

			ret = dfs(next);

			subtree[cur].back() = ret;

			if (ret > 0)
			{
				sum += ret;
			}
		}
	}

	return sum;
}

void dfs2(int cur, int acc)
{
	int sum;

	sum = color[cur] + acc;

	for (int i = 0; i < subtree[cur].size(); i++)
	{
		int next;

		next = graph[cur][i];

		if (!visited2[next])
		{
			if (subtree[cur][i] > 0)
			{
				sum += subtree[cur][i];
			}
		}
	}

	lmax[cur] = sum;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next;

		next = graph[cur][i];

		if (!visited2[next])
		{
			visited2[next] = true;

			int nval;

			nval = sum;

			if (subtree[cur][i] > 0)
			{
				nval -= subtree[cur][i];
			}

			if (nval < 0)
			{
				nval = 0;
			}

			dfs2(next, nval);
		}
	}
}

int main()
{
	int n;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &color[i]);

		color[i] = color[i] * 2 - 1;
	}

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;

		scanf("%d %d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	visited[1] = true;
	dfs(1);

	visited2[1] = true;
	dfs2(1,0);

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", lmax[i]);
	}

	return 0;
}
