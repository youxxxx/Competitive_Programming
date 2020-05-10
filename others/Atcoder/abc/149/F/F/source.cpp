#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

#define MOD 1000000007

using namespace std;

long long n;
vector<long long> graph[200001];
vector<long long> subtree[200001];
long long tot[200001] = { 0, };
bool visited[200001] = { 0, };
bool visited2[200001] = { 0, };

long long dfs(long long cur)
{
	for (long long i = 0; i < graph[cur].size(); i++)
	{
		long long next;

		next = graph[cur][i];

		if (!visited[next])
		{
			visited[next] = true;
			
			long long ret;

			ret = dfs(next);

			subtree[cur].push_back(ret);

			tot[cur] += ret;
		}

		else
		{
			subtree[cur].push_back(0);
		}
	}

	return tot[cur] + 1;
}

void dfs2(long long cur,long long parent,long long add)
{
	if (parent)
	{
		subtree[cur].push_back(add);
	}

	for (long long i = 0; i < graph[cur].size(); i++)
	{
		long long next;

		next = graph[cur][i];

		if (!visited2[next])
		{
			visited2[next] = true;

			dfs2(next, cur, add + tot[cur] + 1 - subtree[cur][i]);
		}
	}
}

long long exp(long long base, long long pw)
{
	long long temp;
	vector<long long> bits;

	temp = pw;

	while (temp)
	{
		bits.push_back(temp % 2);

		temp /= 2;
	}

	temp = base;

	long long rvalue = 1;

	for (long long i = 0; i < bits.size(); i++)
	{
		if (bits[i])
		{
			rvalue = rvalue*temp%MOD;
		}

		temp = temp*temp%MOD;
	}

	return rvalue;
}

long long div(long long val)
{
	return exp(val, MOD - 2);
}

int main()
{
	scanf("%lld", &n);
	
	for (long long i = 0; i < n - 1; i++)
	{
		long long u, v;

		scanf("%lld %lld", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	visited[1] = true;
	dfs(1);
	visited2[1] = true;
	dfs2(1, 0, 0);

	long long lmax = 0;

	vector<pair<long long, long long>> parts;

	for (long long i = 1; i <= n; i++)
	{
		if (!tot[i])
		{
			continue;
		}

		long long curmax = 0;
		long long sum = 1;
		long long divs = 1;

		for (long long j = 0; j < subtree[i].size(); j++)
		{
			if (!subtree[i][j])
			{
				continue;
			}

			sum = (sum + exp(2, subtree[i][j]) + (MOD - 1)) % MOD;
			divs = (divs + subtree[i][j]) % MOD;
		}

		sum = (MOD + exp(2, divs - 1) - sum) % MOD;

		parts.push_back({ sum,divs });

		if (divs > lmax)
		{
			lmax = divs;
		}
	}

	long long divd = 0;
	long long divs;

	divs = exp(2, lmax);

	for (long long i = 0; i < parts.size(); i++)
	{
		long long dd;

		dd = parts[i].first * exp(2, lmax - parts[i].second) % MOD;

		//dd = (MOD + divs - dd) % MOD;

		divd = (divd + dd) % MOD;
	}

	long long sol;

	sol = divd*div(divs) % MOD;

	printf("%lld\n", sol);

	return 0;
}
