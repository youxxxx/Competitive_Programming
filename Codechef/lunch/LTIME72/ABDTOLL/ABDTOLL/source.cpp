#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

vector<int> graph[10001];
vector<int> lmax[10001];
long long vmax[10001];
vector<long long> weight;
long long k;

long long dfs(int cur, int parent)
{
	int i;
	int next;
	long long curmax;

	curmax = weight[cur];

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i];

		if (next == parent)
		{
			lmax[cur].push_back(0);

			continue;
		}

		lmax[cur].push_back(weight[cur] + dfs(next, cur));

		if (lmax[cur].back() > curmax)
		{
			curmax = lmax[cur].back();
		}
	}

	vmax[cur] = curmax;

	return vmax[cur];
}

long long dfs2(int cur, int parent, long long acc)
{
	int i;
	int next;
	long long curmax = 0;
	long long ret;
	long long sum = 0;

	if (acc + weight[cur] >= vmax[cur] - k)
	{
		return vmax[cur] - k - acc > 0 ? vmax[cur] - k - acc:0;
	}

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i];

		if (next == parent)
		{
			continue;
		}

		ret = dfs2(next, cur, acc + weight[cur]);

		sum += ret;
	}	
	
	return sum + weight[cur];
}

void dfs3(int cur, int parent, long long prop)
{
	int i;
	int next;
	long long prev;

	prev = vmax[cur];

	vmax[cur] = prop;

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i];

		if (next == parent)
		{
			continue;
		}

		dfs3(next, cur, prop - (prev - lmax[cur][i]));
	}
}

int main()
{
	int t, z;
	int n, x;
	long long input;
	int i, j;
	int u, v;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d %lld", &n, &x, &k);

		weight.clear();
		weight.push_back(0);

		for (i = 1; i <= n; i++)
		{
			graph[i].clear();
			lmax[i].clear();

			scanf("%lld", &input);
			
			weight.push_back(input);
		}

		for (i = 0; i < n - 1; i++)
		{
			scanf("%d %d", &u, &v);

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		dfs(x, 0);

		dfs3(x, 0, vmax[x]);

		printf("%lld\n", dfs2(x, 0, 0) * 2);
	}

	return 0;
}