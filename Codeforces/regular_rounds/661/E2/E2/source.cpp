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
	bool operator()(const pair<long long, long long> &a, const pair<long long, long long> &b)
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
		int coin[N + 1];

		scanf("%d %lld", &n, &s);

		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
		}

		for (int i = 1; i < n; i++)
		{
			int u, v;
			long long d;

			scanf("%d %d %lld %d", &u, &v, &d, &coin[i]);

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

		vector<long long> v1, v2;

		for (int i = 1; i < n; i++)
		{
			if (coin[i] == 1)
			{
				pq.push({ val[i],cnt[i] });
			}
		}

		while (!pq.empty())
		{
			long long v, c;

			v = pq.top().first;
			c = pq.top().second;

			pq.pop();

			v1.push_back((v - v / 2)*c);

			if (v > 1)
			{
				pq.push({ v / 2,c });
			}
		}

		for (int i = 1; i < n; i++)
		{
			if (coin[i] == 2)
			{
				pq.push({ val[i],cnt[i] });
			}
		}

		while (!pq.empty())
		{
			long long v, c;

			v = pq.top().first;
			c = pq.top().second;

			pq.pop();

			v2.push_back((v - v / 2)*c);

			if (v > 1)
			{
				pq.push({ v / 2,c });
			}
		}

		int ptr1 = 0, ptr2 = 0;
		int sol = 0;

		while (left > 0)
		{
			if (ptr2 == v2.size())
			{
				left -= v1[ptr1++];
				sol++;
			}

			else if (ptr1 == v1.size())
			{
				left -= v2[ptr2++];
				sol += 2;
			}

			else
			{
				if (left <= v1[ptr1])
				{
					left -= v1[ptr1++];
					sol++;
				}

				else if (v1[ptr1] >= v2[ptr2])
				{
					left -= v1[ptr1++];
					sol++;
				}

				else if (ptr1 >= v1.size() - 2)
				{
					left -= v2[ptr2++];
					sol += 2;
				}

				else
				{
					if (v1[ptr1] + v1[ptr1 + 1] <= v2[ptr2])
					{
						left -= v2[ptr2++];
						sol += 2;
					}

					else
					{
						left -= v1[ptr1++];
						sol++;
					}
				}
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}