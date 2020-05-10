#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

vector<int> graph[100001];
int depth[100001];
bool visited[100001] = { 0, };
int ancestor[100001][21];

void dfs(int cur, int curdepth)
{
	depth[cur] = curdepth;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next;

		next = graph[cur][i];

		if (visited[next])
		{
			continue;
		}

		visited[next] = true;

		ancestor[next][0] = cur;

		dfs(next, curdepth + 1);
	}
}

int lca(int x, int y)
{
	if (depth[x] > depth[y])
	{
		int temp;

		temp = x;
		x = y;
		y = temp;
	}

	for (int i = 20; i >= 0; i--)
	{
		if (depth[y] - depth[x] >= (1 << i))
		{
			y = ancestor[y][i];
		}
	}

	if (x == y)
	{
		return x;
	}

	for (int i = 20; i >= 0; i--)
	{
		if (ancestor[x][i] != ancestor[y][i])
		{
			x = ancestor[x][i];
			y = ancestor[y][i];
		}
	}

	return ancestor[x][0];
}

int dist(int x, int y)
{
	int ansc;

	ansc = lca(x, y);

	return depth[x] - depth[ansc] + depth[y] - depth[ansc];
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;

		scanf("%d %d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	visited[1] = true;

	dfs(1, 0);

	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ancestor[j][i] = ancestor[ancestor[j][i - 1]][i - 1];
		}
	}

	int q;

	scanf("%d", &q);

	for (int i = 0; i < q; i++)
	{
		int x, y, a, b, k;

		scanf("%d %d %d %d %d", &x, &y, &a, &b, &k);

		int xy, ab;

		xy = dist(x, y);
		ab = dist(a, b);

		if (ab <= k && !((k - ab) % 2))
		{
			printf("YES\n");

			continue;
		}

		vector<int> cand;
		cand.push_back(dist(a, x) + dist(b, y) + 1);
		cand.push_back(dist(b, x) + dist(a, y) + 1);

		bool found = false;

		for (int i = 0; i < 2; i++)
		{
			if (cand[i] <= k && !((k - cand[i]) % 2) || cand[i] + xy + 1 <= k && !((k - (cand[i] + xy + 1)) % 2))
			{
				found = true;

				break;
			}
		}

		if (found)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}