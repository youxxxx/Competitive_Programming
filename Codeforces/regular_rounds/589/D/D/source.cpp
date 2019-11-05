#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>

#define MOD 1000000007

using namespace std;

vector<int> two, three, graph2[100001];
bool visited[100001] = { 0, };
bool typetwo[100001] = { 0, }, typethree[100001] = { 0, };

void dfs(int cur, int bit)
{
	int i, next;

	for (i = 0; i < graph2[cur].size(); i++)
	{
		next = graph2[cur][i];

		if (!visited[next])
		{
			if (bit == 0)
			{
				three.push_back(next);

				typetwo[cur] = true;
				typethree[next] = true;
			}

			else
			{
				two.push_back(next);

				typetwo[next] = true;
				typethree[cur] = true;
			}

			visited[next] = true;

			dfs(next, !bit);
		}
	}
}

int main()
{
	vector<int> graph[100001];
	int inter1[100001] = { 0, };
	vector<int> tt, one;
	bool notone[100001] = { 0, };
	int n, m;
	int i, j;
	int u, v;
	vector<pair<int, int>> edges;
	int color[100001];

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);

		edges.push_back(pair<int, int>(u, v));

		if (u == 1)
		{
			tt.push_back(v);

			notone[v] = true;
		}

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (i = 1; i <= n; i++)
	{
		if (!notone[i])
		{
			one.push_back(i);
		}
	}

	if (tt.size() == 0 || tt.size() == n || one.size() + tt.size() != n)
	{
		printf("-1\n");

		return 0;
	}

	for (i = 0; i < m; i++)
	{
		u = edges[i].first;
		v = edges[i].second;

		if (!notone[u] && !notone[v])
		{
			printf("-1\n");

			return 0;
		}

		else if (!notone[u] && notone[v])
		{
			inter1[u]++;
		}

		else if (notone[u] && !notone[v])
		{
			inter1[v]++;
		}

		else
		{
			graph2[u].push_back(v);

			graph2[v].push_back(u);
		}
	}

	for (i = 0; i < one.size(); i++)
	{
		if (inter1[one[i]] != tt.size())
		{
			printf("-1\n");

			return 0;
		}
	}

	for (i = 1; i <= n; i++)
	{
		if (notone[i])
		{
			typetwo[i] = true;
			
			two.push_back(i);

			visited[i] = true;

			dfs(i, 0);

			break;
		}
	}

	if (two.size() == 0 || two.size() == tt.size() || two.size() + three.size() != tt.size())
	{
		printf("-1\n");

		return 0;
	}

	for (i = 0; i < m; i++)
	{
		u = edges[i].first;
		v = edges[i].second;

		if (notone[u] && notone[v])
		{
			if (typetwo[u] && typetwo[v] || typethree[u] && typethree[v])
			{
				printf("-1\n");

				return 0;
			}
		}
	}

	for (i = 0; i < two.size(); i++)
	{
		if (graph2[two[i]].size() != three.size())
		{
			printf("-1\n");

			return 0;
		}
	}

	for (i = 0; i < three.size(); i++)
	{
		if (graph2[three[i]].size() != two.size())
		{
			printf("-1\n");

			return 0;
		}
	}

	for (i = 1; i <= n; i++)
	{
		if (!notone[i])
		{
			printf("1 ");
		}

		else
		{
			if (typetwo[i])
			{
				printf("2 ");
			}

			else
			{
				printf("3 ");
			}
		}
	}

	return 0;
}