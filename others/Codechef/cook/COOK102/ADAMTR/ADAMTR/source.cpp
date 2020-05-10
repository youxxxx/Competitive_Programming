#include<cstdio>
#include<vector>
#include<stack>

using namespace std;

vector<pair<int, int>> logics;
int n;
int **a, **b;
bool valid;
vector<pair<int, int>> graph[1024][2], revgraph[1024][2];
bool visited[1024][2];
bool visited2[1024][2];
bool marked[1024][2];
int logic, not;
int nextlog, nextnot;
int scnt;
int snum[1024][2];

void dfs(int lognum, int notnum, vector<pair<int,int>> &result)
{
	int i;
	int nextlog, nextnot;

	for (i = 0; i < revgraph[lognum][notnum].size(); i++)
	{
		nextlog = revgraph[lognum][notnum][i].first;
		nextnot = revgraph[lognum][notnum][i].second;

		if (!visited[nextlog][nextnot])
		{
			visited[nextlog][nextnot] = true;

			dfs(nextlog, nextnot, result);
		}
	}

	result.insert(result.begin(),pair<int, int>(lognum, notnum));
}

void dfs2(int lognum, int notnum, int label)
{
	int i;
	int nextlog, nextnot;

	snum[lognum][notnum] = label;

	for (i = 0; i < graph[lognum][notnum].size(); i++)
	{
		nextlog = graph[lognum][notnum][i].first;
		nextnot = graph[lognum][notnum][i].second;

		if (!visited2[nextlog][nextnot])
		{
			visited2[nextlog][nextnot] = true;

			dfs2(nextlog, nextnot, label);
		}
	}
}

int main()
{
	int t, z;
	int i, j;

	a = new int*[1024];
	b = new int*[1024];

	for (i = 0; i < 1024; i++)
	{
		a[i] = new int[1024];

		b[i] = new int[1024];
	}

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		valid = true;

		scnt = 0;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &a[i][j]);
			}

			visited[i][0] = visited[i][1] = marked[i][0] = marked[i][1] = false;
			visited2[i][0] = visited2[i][1] = false;
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &b[i][j]);
			}
		}

		for (i = 0; i < n; i++)
		{
			if (a[i][i] != b[i][i])
			{
				valid = false;

				break;
			}

			for (j = 1; j < n; j++)
			{
				if (!((a[i][j] == b[i][j] && a[j][i] == b[j][i]) || (a[i][j] == b[j][i] && a[j][i] == b[i][j])))
				{
					valid = false;

					break;
				}

				else if (a[i][j] != a[j][i])
				{
					if (a[i][j] == b[i][j])
					{
						graph[i][0].push_back(pair<int, int>(j, 0));
						revgraph[j][0].push_back(pair<int, int>(i, 0));
						graph[i][1].push_back(pair<int, int>(j, 1));
						revgraph[j][1].push_back(pair<int, int>(i, 1));
						revgraph[i][0].push_back(pair<int, int>(j, 0));
						graph[j][0].push_back(pair<int, int>(i, 0));
						revgraph[i][1].push_back(pair<int, int>(j, 1));
						graph[j][1].push_back(pair<int, int>(i, 1));
					}

					else
					{
						graph[i][0].push_back(pair<int, int>(j, 1));
						graph[j][0].push_back(pair<int, int>(i, 1));
						revgraph[i][1].push_back(pair<int, int>(j, 0));
						revgraph[j][1].push_back(pair<int, int>(i, 0));
						revgraph[i][0].push_back(pair<int, int>(j, 1));
						revgraph[j][0].push_back(pair<int, int>(i, 1));
						graph[i][1].push_back(pair<int, int>(j, 0));
						graph[j][1].push_back(pair<int, int>(i, 0));
					}
				}
			}

			if (!valid)
			{
				break;
			}
		}

		if (!valid)
		{
			printf("No\n");

			for (i = 0; i < n; i++)
			{
				graph[i][0].clear();

				graph[i][1].clear();

				revgraph[i][0].clear();

				revgraph[i][1].clear();
			}

			continue;
		}

		/*
		for (i = 0; i < n; i++)
		{
			if (!visited[i][0])
			{
				snum[i][0] = scnt;
				visited[i][0] = true;

				s.push(pair<int, int>(i, 0));

				while (!s.empty())
				{
					cur = s.top();
					s.pop();

					logic = cur.first;
					not = cur.second;

					for (i = 0; i < graph[logic][not].size(); i++)
					{
						nextlog = graph[logic][not][i].first;
						nextnot = graph[logic][not][i].second;
						if (!visited[nextlog][nextnot])
						{
							visited[nextlog][nextnot] = true;

							snum[nextlog][nextnot] = scnt;

							s.push(pair<int, int>(nextlog, nextnot));
						}
					}
				}

				scnt++;

				if (visited[i][1])
				{
					valid = false;

					break;
				}
			}

			if (!visited[i][1])
			{
				snum[i][1] = scnt;
				visited[i][1] = true;

				s.push(pair<int, int>(i, 1));

				while (!s.empty())
				{
					cur = s.top();
					s.pop();

					logic = cur.first;
					not= cur.second;

					for (i = 0; i < graph[logic][not].size(); i++)
					{
						nextlog = graph[logic][not][i].first;
						nextnot = graph[logic][not][i].second;

						if (!visited[nextlog][nextnot])
						{
							visited[nextlog][nextnot] = true;

							snum[nextlog][nextnot] = scnt;

							s.push(pair<int, int>(nextlog, nextnot));
						}
					}
				}
			}
		}
		*/

		for (i = 0; i < n; i++)
		{
			if (!visited[i][0])
			{
				visited[i][0] = true;

				dfs(i, 0, logics);
			}

			if (!visited[i][1])
			{
				visited[i][1] = true;

				dfs(i, 1, logics);
			}
		}

		for (i = 0; i < logics.size(); i++)
		{
 			if (!visited2[logics[i].first][logics[i].second])
			{
				visited2[logics[i].first][logics[i].second] = true;

				dfs2(logics[i].first, logics[i].second, scnt++);
			}
		}

		for (i = 0; i < n; i++)
		{
			if (snum[i][0] == snum[i][1])
			{
				valid = false;

				break;
			}
		}

		if (!valid)
		{
			printf("No\n");

			for (i = 0; i < n; i++)
			{
				graph[i][0].clear();

				graph[i][1].clear();

				revgraph[i][0].clear();

				revgraph[i][1].clear();

				logics.clear();
			}

			continue;
		}

		printf("Yes\n");

		for (i = 0; i < n; i++)
		{
			graph[i][0].clear();

			graph[i][1].clear();

			revgraph[i][0].clear();

			revgraph[i][1].clear();

			logics.clear();
		}
	}

	return 0;
}