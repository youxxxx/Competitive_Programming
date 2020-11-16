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

#define N 100001

vector<pair<int, int>> graph[N + 1];
long long cnt[N + 1];

long long dfs(int cur, int parent)
{
	if (!(graph[cur].size() - !!parent))
	{
		return 1;
	}

	long long rvalue = 0;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		const int next = graph[cur][i].first;
		const int idx = graph[cur][i].second;

		if (next == parent)
		{
			continue;
		}

		cnt[idx] = dfs(next, cur);

		rvalue += cnt[idx];
	}

	return rvalue;
}

class comp
{
public:
	bool operator()(const pair<long long,long long> &a, const pair<long long, long long> &b)
	{
		return (a.first - a.first / 2)*a.second < (b.first - b.first / 2)*b.second;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long val[N + 1];
		int n;
		long long s;

		scanf("%d %lld", &n, &s);

		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
		}

		for (int i = 1; i < n; i++)
		{
			int u, v;
			long long d;

			scanf("%d %d %lld", &u, &v, &d);

			graph[u].push_back({ v,i });
			graph[v].push_back({ u,i });

			val[i] = d;
		}

		dfs(1, 0);

		long long tot = 0;

		for (int i = 1; i < n; i++)
		{
			tot += val[i] * cnt[i];
		}

		long long left = tot - s;

		if (left <= 0)
		{
			printf("0\n");

			continue;
		}

		priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, comp> pq;

		for (int i = 1; i < n; i++)
		{
			pq.push({ val[i],cnt[i] });
		}

		int sol = 0;

		while (left > 0)
		{
			sol++;

			long long v, c;

			v = pq.top().first;
			c = pq.top().second;

			pq.pop();

			left -= (v - v / 2)*c;

			if (v > 1)
			{
				pq.push({ v / 2,c });
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}