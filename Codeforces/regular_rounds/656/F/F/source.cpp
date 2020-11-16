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
vector<int> graph[200001];

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{

		int n, k;

		scanf("%d %d", &n, &k);

		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
		}

		for (int i = 0; i < n - 1; i++)
		{
			int u, v;

			scanf("%d %d", &u, &v);

			graph[u].push_back(v);

			graph[v].push_back(u);
		}

		int deg[200001];
		bool cut[200001];

		for (int i = 1; i <= n; i++)
		{
			deg[i] = cut[i] = 0;
		}

		for (int i = 1; i <= n; i++)
		{
			if (graph[i].size() == 1)
			{
				deg[graph[i][0]]++;

				cut[i] = true;
			}
		}

		queue<int> q;

		for (int i = 1; i <= n; i++)
		{
			if (deg[i] && !(deg[i] % k) && deg[i] + 1 == graph[i].size())
			{
				q.push(i);
			}
		}

		int sol = 0;

		while (!q.empty())
		{
			const int cur = q.front();
			q.pop();

			sol += deg[cur] / k;
			cut[cur] = true;

			deg[cur] = 0;

			for (int i = 0; i < graph[cur].size(); i++)
			{
				const int next = graph[cur][i];

				if (++deg[next] + 1 == graph[next].size() && !cut[next] && !(deg[next] % k))
				{
					q.push(next);
				}
			}
		}

		for (int i = 1; i <= n; i++)
		{
			if (!cut[i])
			{
				sol += deg[i] / k;

				deg[i] %= k;
			}
		}

		if (k == 1 && sol*k + 1 == n - 1)
		{
			sol++;
		}

		printf("%d\n", sol);
	}

	return 0;
}