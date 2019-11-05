#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n;
int *p;
int *vtime;
int *sol;
bool *visited;
int input;
int root;
vector<int>* rindex;
queue<int> q, q2;

void dfs(int cur, int lab)
{
	int i, next;

	for (i = 0; i < rindex[cur].size(); i++)
	{
		if (!visited[rindex[cur][i]])
		{
			next = rindex[cur][i];

			visited[next] = true;

			sol[next] = lab;

			dfs(next, lab);
		}
	}
}

int main()
{
	int i, j;
	int cur;

	scanf("%d", &n);

	p = new int[n + 1];
	vtime = new int[n + 1];
	visited = new bool[n + 1];
	sol = new int[n + 1];
	rindex = new vector<int>[n + 1];

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);

		rindex[p[i]].push_back(i);

		visited[i] = false;
	}

	for (i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			q.push(i);
			cur = p[i];
			visited[i] = true;

			while (!q.empty())
			{
				if (visited[cur])
				{
					root = cur;

					cur = q.front();

					q.pop();

					while (cur != root)
					{
						visited[cur] = false;

						cur = q.front();

						q.pop();
					}

					sol[root] = root;

					for (j = 0; j < rindex[root].size(); j++)
					{
						if (!visited[rindex[root][j]])
						{
							sol[rindex[root][j]] = root;
							visited[rindex[root][j]] = true;
 							dfs(rindex[root][j], root);
						}
					}

					while (!q.empty())
					{
						cur = q.front();

						q.pop();

						sol[cur] = cur;

						for (j = 0; j < rindex[cur].size(); j++)
						{
							if (!visited[rindex[cur][j]])
							{
								sol[rindex[cur][j]] = cur;
								visited[rindex[cur][j]] = true;
								dfs(rindex[cur][j], cur);
							}
						}
					}
					
					break;
				}

				q.push(cur);

				visited[cur] = true;

				cur = p[cur];
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		printf("%d ", sol[i]);
	}

	return 0;
}