#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

pair<long long,long long> sum(vector<vector<long long>> &tree, vector<long long> &cost,long long cur,long long ansc)
{
	long long i, next;
	long long total;
	pair<long long, long long> rvalue, ret;

	rvalue.first = 0;
	rvalue.second = 0;

	if (tree[cur].size() == 1)
	{
		rvalue.first = 0;
		rvalue.second = 1;

		return rvalue;
	}

	for (i = 1; i < tree[cur].size(); i++)
	{
		next = tree[cur][i];

		if (next == ansc)
		{
			continue;
		}

		ret = sum(tree, cost, next, cur);

		rvalue.first += ret.first;
		rvalue.second += ret.second;
	}

	cost[cur] = total;

	return rvalue;
}

int main()
{
	vector<long long> fact;
	vector<vector<long long>> tree;
	vector<long long> cost;
	vector<long long> zero;
	long long i;
	long long n, q;
	long long u, v;
	pair<long long, pair<long long, long long>> cur;

	int t, z;
	/*
	fact.push_back(0);
	fact.push_back(1);

	for (i = 2; i <= 5000050001; i++)
	{
		fact.push_back((fact[i - 1] * i) % 99991);
	}
	*/
	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%lld", &n);

		for (i = 0; i <= n; i++)
		{
			tree.push_back(zero);

			cost.push_back(0);
		}

		for (i = 0; i < n - 1; i++)
		{
			scanf("%lld %lld", &u, &v);

			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		sum(tree, cost, 1, 0, n - 2);

		cost[1]++;

		scanf("%lld", &q);

		for (i = 0; i < q; i++)
		{
			scanf("%lld", &u);

			//printf("%lld\n",fact[cost[u]]);

			printf("%lld\n", cost[u]);
		}

		tree.clear();
		cost.clear();
	}

	return 0;
}