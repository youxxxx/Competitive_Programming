#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

#define MOD 998244353

using namespace std;

vector<int> graph[200001];
long long level[200001];
long long lcnt[200001] = { 0, };
long long fac[200001];

/*
void dfs(int cur, int parent, long long curlev)
{
	int next;
	int i;

	level[cur] = curlev;
	lcnt[curlev]++;

	if (curlev > lmax)
	{
		lmax = curlev;
	}

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i];

		if (next == parent)
		{
			continue;
		}

		dfs(next, cur, curlev + 1);
	}
}
*/

long long dfs(int cur, int parent)
{
	int next;
	int i;
	long long rvalue = 1, cnt = 0;

	for (i = 0; i < graph[cur].size(); i++)
	{
 		next = graph[cur][i];

		if (next == parent)
		{
			continue;
		}

		rvalue = (rvalue * dfs(next, cur)) % MOD;

		cnt++;
	}

	if (cnt == 0)
	{
		return 1;
	}

	if (cur == 1)
	{
		return rvalue*fac[cnt] % MOD;
	}

	return (rvalue * fac[cnt + 1]) % MOD;
}

int main()
{
	long long n;
	long long sol = 1;
	long long i;
	int u, v;

	scanf("%lld", &n);

	fac[1] = 1;

	for (i = 2; i <= n; i++)
	{
		fac[i] = (fac[i - 1] * i) % MOD;
	}

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	printf("%lld\n", (dfs(1, 0))*n%MOD);

	return 0;
}