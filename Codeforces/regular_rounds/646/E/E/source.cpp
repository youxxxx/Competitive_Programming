#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

vector<long long> graph[200001];
long long cost[200001];
long long color[200001];
long long target[200001];

pair<long long, pair<long long,long long>> dfs(long long cur, long long parent, long long pcost)
{
	if (cost[cur] < pcost)
	{
		pcost = cost[cur];
	}
	
	pair<long long, pair<long long, long long>> rvalue = { 0,{0,0} };

	for (long long i = 0; i < graph[cur].size(); i++)
	{
		const long long next = graph[cur][i];

		if (next == parent)
		{
			continue;
		}

		const pair<long long, pair<long long, long long>> ret = dfs(next, cur, pcost);

		rvalue.first += ret.first;
		rvalue.second.first += ret.second.first;
		rvalue.second.second += ret.second.second;
	}

	if (color[cur] != target[cur])
	{
		if (target[cur] == 0)
		{
			rvalue.second.first++;
		}

		else
		{
			rvalue.second.second++;
		}
	}

	const long long lmin = rvalue.second.first < rvalue.second.second ? rvalue.second.first : rvalue.second.second;

	rvalue.first += lmin*pcost * 2;
	rvalue.second.first -= lmin;
	rvalue.second.second -= lmin;

	return rvalue;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	long long n;

	scanf("%lld", &n);

	long long cnt[2] = { 0, };

	for (long long i = 1; i <= n; i++)
	{
		scanf("%lld %lld %lld", &cost[i], &color[i], &target[i]);

		cnt[color[i]]++;
		cnt[target[i]]--;
	}

	if (cnt[0])
	{
		printf("-1\n");

		return 0;
	}

	for (long long i = 0; i < n - 1; i++)
	{
		long long u, v;

		scanf("%lld %lld", &u, &v);

		graph[u].push_back(v);

		graph[v].push_back(u);
	}

	const pair<long long, pair<long long, long long>> ret = dfs(1, 0, cost[1]);

	printf("%lld\n", ret.first);
	
	return 0;
}