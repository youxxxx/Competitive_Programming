#include<cstdio>
#include<vector>
#include<set>
#include<queue>

using namespace std;

int main()
{
	int n, k;
	vector<int> *graph;
	int i, j;
	int *level;
	int *degree;
	int a, b;
	queue<int> q[2];
	vector<set<int>> ordered;
	set<int> curset;
	set<int>::iterator it;
	int cur;
	int cnt = 0;

	scanf("%d %d", &n, &k);

	graph = new vector<int>[n + 1];
	level = new int[n + 1];
	degree = new int[n + 1];

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &a, &b);

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (i = 1; i <= n; i++)
	{
		level[i] = 0;

		degree[i] = graph[i].size();
	}

	for (i = 1; i <= n; i++)
	{
		if (graph[i].size() == 1)
		{
			level[i] = 1;

			q[0].push(i);
		}
	}
/*
	for (i = 1; i <= k; i++)
	{
		while (!q[!(i % 2)].empty())
		{
			cur = q[!(i % 2)].front();

			q[!(i % 2)].pop();

			for (j = 0; j < graph[cur].size(); j++)
			{
				if (!(level[graph[cur][j]] == 0 || level[graph[cur][j]] == i - 1 || level[graph[cur][j]] == i + 1 && degree[graph[cur][j]] >= 4 - i / k))
				{
					printf("No\n");

					return 0;
				}

				if (level[graph[cur][j]] == 0)
				{
					level[graph[cur][j]] = i + 1;

					q[i % 2].push(graph[cur][j]);
				}

				cnt++;
			}
		}
	}
*/

	for (i = 1; i <= k; i++)
	{
		while (!q[!(i % 2)].empty())
		{
			cur = q[!(i % 2)].front();

			q[!(i % 2)].pop();

			for (j = 0; j < graph[cur].size(); j++)
			{
				if (level[graph[cur][j]] == 0)
				{
					level[graph[cur][j]] = i + 1;

					if (degree[graph[cur][j]] < 4 - i/k)
					{
						printf("No\n");

						return 0;
					}

//					curset.insert(graph[cur][j]);

					q[(i % 2)].push(graph[cur][j]);
				}
			}
		}

//		ordered.push_back(curset);

//		curset.clear();
	}

	if (!(q[(k % 2)].size() == 1 && degree[q[(k % 2)].front()] >= 3))
	{
		printf("No\n");

		return 0;
	}
	/*
	for (i = 1; i <= k; i++)
	{
		for (it = ordered[i - 1].begin(); it != ordered[i - 1].end(); it++)
		{
			if (degree[*it] < 4 - i / k)
			{
				printf("No\n");

				return 0;
			}
		}
	}
	*/
	printf("Yes\n");

	return 0;
}