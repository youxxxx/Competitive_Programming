#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int root[100];
int in[100];
bool visited[100];
bool sheet[100];
vector<int> ingraph[100], outgraph[100], sub[100], nonsub[100];
int relation[100][100];

void dfs(int cur)
{
	int i;
	int next;

	sheet[cur] = true;

	for (i = 0; i < ingraph[cur].size(); i++)
	{
		next = ingraph[cur][i];

		dfs(next);
	}
}

int main()
{
	int t, z;
	int n, m;
	int x, y, a;
	int i, j;
	queue<int> q;
	int cur, last;
	bool valid;

	freopen("trees_as_a_service.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &m);

		for (i = 1; i <= n; i++)
		{
			root[i] = 0;
			in[i] = 0;
			visited[i] = false;
			ingraph[i].clear();
			outgraph[i].clear();
			sub[i].clear();
			nonsub[i].clear();

			for (j = 1; j <= n; j++)
			{
				relation[i][j] = -1;
			}
		}

		for (i = 0; i < m; i++)
		{
			scanf("%d %d %d", &x, &y, &a);

			if (x == a)
			{
				in[a]++;
				ingraph[a].push_back(y);
				outgraph[y].push_back(a);

				sub[a].push_back(y);
			}

			else if (y == a)
			{
				in[a]++;
				ingraph[a].push_back(x);
				outgraph[x].push_back(a);

				sub[a].push_back(x);
			}

			else
			{
				in[a] += 2;
				ingraph[a].push_back(y);
				outgraph[y].push_back(a);
				ingraph[a].push_back(x);
				outgraph[x].push_back(a);

				sub[a].push_back(y);
				sub[a].push_back(x);

				nonsub[x].push_back(y);
				nonsub[y].push_back(x);
			}
		}

		for (i = 1; i <= n; i++)
		{
			if (in[i] == 0)
			{
				q.push(i);
			}
		}

		while (!q.empty())
		{
			cur = q.front();
			q.pop();

			for (i = 0; i < ingraph[cur].size(); i++)
			{
				if (!visited[ingraph[cur][i]])
				{
					visited[ingraph[cur][i]] = true;

					root[ingraph[cur][i]] = cur;
				}
			}

			for (i = 0; i < outgraph[cur].size(); i++)
			{
				if (--in[outgraph[cur][i]] == 0)
				{
					q.push(outgraph[cur][i]);
				}
			}

			last = cur;
		}

		root[last] = 0;

		valid = true;

		for (i = 1; i <= n; i++)
		{
			if (in[i] != 0)
			{
				break;
			}

			for (j = 1; j <= n; j++)
			{
				sheet[j] = false;
			}

			dfs(i);

			for (j = 0; j < sub[i].size(); j++)
			{
				if (!sheet[sub[i][j]])
				{
					valid = false;

					break;
				}
			}

			if (!valid)
			{
				break;
			}

			for (j = 0; j < nonsub[i].size(); j++)
			{
				if (sheet[nonsub[i][j]])
				{
					valid = false;

					break;
				}
			}

			if (!valid)
			{
				break;
			}

			if (root[i] == 0 && i != last)
			{
				root[i] = last;
			}
		}

		if (i != n + 1)
		{
			printf("Case #%d: Impossible\n", z + 1);
		}

		else
		{
			printf("Case #%d:", z + 1);

			for (i = 1; i <= n; i++)
			{
				printf(" %d", root[i]);
			}

			printf("\n");
		}
	}

	return 0;
}