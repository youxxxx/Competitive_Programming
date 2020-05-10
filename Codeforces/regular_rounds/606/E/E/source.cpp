#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

bool aside[200001];
bool bside[200001];

vector<int> graph[200001];

void adfs(int cur, int stop)
{
	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next;

		next = graph[cur][i];

		if (next == stop || aside[next])
		{
			continue;
		}

		aside[next] = true;

		adfs(next, stop);
	}
}

void bdfs(int cur, int stop)
{
	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next;

		next = graph[cur][i];

		if (next == stop || bside[next])
		{
			continue;
		}

		bside[next] = true;

		bdfs(next, stop);
	}
}

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m, a, b;

		scanf("%d %d %d %d", &n, &m, &a, &b);

		for (int i = 1; i <= n; i++)
		{
			aside[i] = bside[i] = false;
			
			graph[i].clear();
		}

		for (int i = 0; i < m; i++)
		{
			int u, v;

			scanf("%d %d", &u, &v);

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		aside[a] = true;
		aside[b] = true;

		adfs(a,b);

		bside[a] = true;
		bside[b] = true;

		bdfs(b, a);

		int tot[2] = { 0, };

		for (int i = 1; i <= n; i++)
		{
			if (aside[i] && !bside[i])
			{
				tot[0]++;
			}

			else if (!aside[i] && bside[i])
			{
				tot[1]++;
			}
		}

		printf("%lld\n", (long long)tot[0] * (long long)tot[1]);
	}

	return 0;
}