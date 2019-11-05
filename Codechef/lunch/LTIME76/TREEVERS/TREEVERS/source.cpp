#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int> graph[100001];
long long w[100001];
long long tot[100001][2];
long long sol;

bool func(pair<long long, long long> &a, pair<long long, long long> &b)
{
	double ar, br;

	if (a.second == 0)
	{
		return true;
	}

	if (b.second == 0)
	{
		return false;
	}

	ar = (double)a.first / (double)a.second;
	br = (double)b.first / (double)b.second;

	return ar > br;
}

class comp
{
public:
	bool operator() (const pair<long long, long long> &a, const pair<long long, long long> &b)
	{
		double ar, br;

		if (a.second == 0)
		{
			return false;
		}

		if (b.second == 0)
		{
			return true;
		}

		ar = (double)a.first / (double)a.second;
		br = (double)b.first / (double)b.second;

		return ar < br;
	}
};

void dfs(int cur, int parent)
{
	//vector<pair<long long, long long>> arr;
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, comp> pq;
	int i;
	int next, next2;
	long long acc;

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i];

		if (next == parent)
		{
			continue;
		}

		dfs(next, cur);

		tot[cur][0] += tot[next][0];
		tot[cur][1] += tot[next][1];

		//arr.push_back(make_pair(tot[next][0], tot[next][1]));
		pq.push(make_pair(tot[next][0], tot[next][1]));
	}

	/*
	if (!arr.empty())
	{
		sort(arr.begin(), arr.end(), func);

		acc = arr[0].second;

		for (i = 1; i < arr.size(); i++)
		{
			sol += acc*arr[i].first;

			acc += arr[i].second;
		}
	}
	*/

	if (!pq.empty())
	{
		acc = pq.top().second;

		pq.pop();

		while(!pq.empty())
		{
			sol += acc*pq.top().first;

			acc += pq.top().second;

			pq.pop();
		}
	}

	if (w[cur])
	{
		sol += tot[cur][0];
	}

	tot[cur][w[cur]]++;
}

int main()
{
	int tc, cases;
	int n;
	int i, j;
	int u, v;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d", &n);

		for (i = 1; i <= n; i++)
		{
			scanf("%lld", &w[i]);

			graph[i].clear();

			tot[i][0] = tot[i][1] = 0;
		}

		for (i = 0; i < n - 1; i++)
		{
			scanf("%d %d", &u, &v);

			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		
		sol = 0;

		dfs(1, 0);

		printf("%lld\n", sol);
	}

	return 0;
}