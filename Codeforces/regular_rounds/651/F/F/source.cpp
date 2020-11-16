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

using namespace std;

int n;

vector<int> graph[1001];
vector<int> dist[1001];
int val[1001];
bool path[1001];

void dfs(int cur, int curdist)
{
	for (int i = 0; i < graph[cur].size(); i++)
	{
		const int next = graph[cur][i];

		if (val[next] == -1)
		{
			val[next] = curdist + 1;

			dist[curdist + 1].push_back(next);

			dfs(next, curdist + 1);
		}
	}
}

void dfs2(int cur, int target)
{
	for (int i = 0; i < graph[cur].size(); i++)
	{
		const int next = graph[cur][i];

		if (!path[next])
		{
			path[next] = true;

			if (next != target)
			{
				dfs2(next, target);
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
			dist[i].clear();

			val[i] = -1;
			path[i] = false;
		}

		for (int i = 0; i < n - 1; i++)
		{
			int u, v;

			scanf("%d %d", &u, &v);

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		printf("? %d", n);

		for (int i = 1; i <= n; i++)
		{
			printf(" %d", i);
		}

		printf("\n");
		fflush(stdout);

		int base, basedist;

		scanf("%d %d", &base, &basedist);

		val[base] = 0;
		dist[0].push_back(base);

		dfs(base, 0);

		int lb = basedist / 2 + (basedist % 2), ub = basedist + 1;

		int lastv = base;

		for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
		{
			if (dist[next].empty())
			{
				ub = next;

				continue;
			}

			printf("? %d", dist[next].size());

			for (int i = 0; i < dist[next].size(); i++)
			{
				printf(" %d", dist[next][i]);
			}

			printf("\n");
			fflush(stdout);

			int v, d;

			scanf("%d %d", &v, &d);
			if (v == -1)
			{
				return 0;
			}

			if (d == basedist)
			{
				lastv = v;

				lb = next;
			}

			else
			{
				ub = next;
			}
		}

		if (lb == basedist / 2 + (basedist % 2))
		{
			printf("? %d", dist[basedist / 2 + (basedist % 2)].size());

			for (int i = 0; i < dist[basedist / 2 + (basedist % 2)].size(); i++)
			{
				printf(" %d", dist[basedist / 2 + (basedist % 2)][i]);
			}

			printf("\n");
			fflush(stdout);

			int v, d;

			scanf("%d %d", &v, &d);
			if (v == -1)
			{
				return 0;
			}

			lastv = v;
		}

		const int other = basedist - lb;

		int sol;

		if (!other)
		{
			sol = base;
		}

		else
		{
			path[lastv] = true;
			dfs2(lastv, base);

			vector<int> list;

			for (int i = 0; i < dist[other].size(); i++)
			{
				if (!path[dist[other][i]])
				{
					list.push_back(dist[other][i]);
				}
			}

			printf("? %d", list.size());

			for (int i = 0; i < list.size(); i++)
			{
				printf(" %d", list[i]);
			}

			printf("\n");
			fflush(stdout);

			int v, d;

			scanf("%d %d", &v, &d);
			if (v == -1)
			{
				return 0;
			}

			sol = v;
		}

		printf("! %d %d\n", lastv, sol);
		fflush(stdout);

		char input[20];
		string check;

		scanf("%s", input);
		check = input;

		if (check == "Incorrect")
		{
			return 0;
		}
	}

	return 0;
}