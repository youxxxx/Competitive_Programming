#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

vector<int> graph[100001];
vector<pair<int, int>> tree[100001];
int tot[100001];
int lmax[100001];

int dfs(int cur,int parent)
{
	int rvalue = 0;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		const int next = graph[cur][i];

		if (next == parent)
		{
			continue;
		}

		int ret = dfs(next, cur);

		tree[cur].push_back({ next,ret });

		tot[cur] += ret;

		rvalue += ret;
	}

	return rvalue + 1;
}

void dfs2(int cur, int parent, int add)
{
	for (int i = 0; i < tree[cur].size(); i++)
	{
		const int next = tree[cur][i].first;

		dfs2(next, cur, add + tot[cur] - tree[cur][i].second + 1);

		if (tree[cur][i].second > lmax[cur])
		{
			lmax[cur] = tree[cur][i].second;
		}
	}

	if (add)
	{
		if (add > lmax[cur])
		{
			lmax[cur] = add;
		}

		tree[cur].push_back({ parent,add });
	}
}

int leaf;
int leafp;

void dfs3(int cur, int parent)
{
	int cnt = 0;

	for (int i = 0; i < tree[cur].size(); i++)
	{
		const int next = tree[cur][i].first;

		if (next == parent)
		{
			continue;
		}

		dfs3(next, cur);

		cnt++;
	}

	if (!cnt)
	{
		leaf = cur;
		leafp = parent;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
			tree[i].clear();
			tot[i] = 0;
			lmax[i] = 0;
		}

		for (int i = 0; i < n - 1; i++)
		{
			int u, v;

			scanf("%d %d", &u, &v);

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		dfs(1, 0);
		dfs2(1, 0, 0);

		int nodemin = 100001;
		vector<int> minidx;

		for (int i = 1; i <= n; i++)
		{
			if (lmax[i] < nodemin)
			{
				nodemin = lmax[i];

				minidx.clear();
				minidx.push_back(i);
			}

			else if (lmax[i] == nodemin)
			{
				minidx.push_back(i);
			}
		}

		if (minidx.size() == 1)
		{
			printf("1 %d\n1 %d\n", graph[1][0], graph[1][0]);

			continue; 
		}

		const int u = minidx[0];
		const int v = minidx[1];

		dfs3(u, v);

		printf("%d %d\n%d %d\n", leaf, leafp, leaf, v);
	}

	return 0;
}