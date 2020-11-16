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

#define MOD 1000000007

long long tot[100001];
vector<long long> sub[100001];
vector<int> graph[100001];
map<int, int> idx[100001];
int pnode[100001];
vector<long long> path;

long long dfs(int cur, int parent)
{
	int cnt = 0;

	pnode[cur] = parent;

	long long rvalue = 1;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		const int next = graph[cur][i];

		if (next == parent)
		{
			continue;
		}

		idx[cur][next] = cnt++;

		const long long ret = dfs(next, cur);

		sub[cur].push_back(ret);

		rvalue += ret;

		tot[cur] += ret;
	}

	if (parent)
	{
		idx[cur][parent] = cnt;
	}

	return rvalue;
}

void dfs2(int cur, int parent)
{
	if (parent)
	{
		const long long val = tot[parent] - sub[parent][idx[parent][cur]] + 1;

		sub[cur].push_back(val);

		tot[cur] += val;
	}

	for (int i = 0; i < graph[cur].size(); i++)
	{
		const int next = graph[cur][i];

		if (next == parent)
		{
			continue;
		}

		dfs2(next, cur);
	}
}

void dfs3(int cur, int parent)
{
	for (int i = 0; i < graph[cur].size(); i++)
	{
		const int next = graph[cur][i];

		if (next == parent)
		{
			continue;
		}

		const long long val = (tot[cur] - sub[cur][idx[cur][next]] + 1)*(tot[next] - sub[next][idx[next][cur]] + 1);

		path.push_back(val);

		dfs3(next, cur);
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

		for (int i = 0; i <= n; i++)
		{
			tot[i] = 0;

			graph[i].clear();
			sub[i].clear();
			idx[i].clear();
		}

		path.clear();

		for (int i = 0; i < n - 1; i++)
		{
			int u, v;

			scanf("%d %d", &u, &v);

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		int m;

		scanf("%d", &m);

		long long prime[60001];

		for (int i = 0; i < m; i++)
		{
			scanf("%lld", &prime[i]);
		}

		sort(&prime[0], &prime[m], greater<long long>());

		dfs(1, 0);
		dfs2(1, 0);
		dfs3(1, 0);

		sort(path.begin(), path.end(), greater<long long>());

		long long sol = 0;
		
		if (m > n - 1)
		{
			long long prod = 1;

			for (int i = 0; i <= m - (n - 1); i++)
			{
				prod = (prod * prime[i]) % MOD;
			}

			sol = (sol + prod*path[0]) % MOD;

			for (int i = m - (n - 2); i < m; i++)
			{
				sol = (sol + path[i - (m - (n - 1))] * prime[i] % MOD) % MOD;
			}
		}

		else
		{
			for (int i = 0; i < m; i++)
			{
				sol = (sol + prime[i] * path[i] % MOD) % MOD;
			}

			for (int i = m; i < n - 1; i++)
			{
				sol = (sol + path[i]) % MOD;
			}
		}

		printf("%lld\n", sol);
	}

	return 0;
}