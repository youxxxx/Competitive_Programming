#include<cstdio>
#include<vector>
#include<stack>
#include<set>

using namespace std;

int main()
{
	int n, m;
	int t, z;
	bool **graph;
	int *degree;
	bool tri;
	int cnt;
	int max;
	int next;
	int i, j;
	int last;
	int x, y;
	stack<int> s;

	scanf("%d", &t);

	degree = new int[10001];
	graph = new bool*[10001];

	for (i = 1; i <= 10000; i++)
	{
		graph[i] = new bool[10001];
	}

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &m);

		tri = false;

		for (i = 1; i <= n; i++)
		{
			degree[i] = 0;

			for (j = 1; j <= n; j++)
			{
				graph[i][j] = false;
			}
		}

		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &x, &y);

			degree[x]++;
			degree[y]++;

			if (!tri)
			{
				for (j = 1; j <= n; j++)
				{
					if (j == x || j == y)
					{
						continue;
					}

					if (graph[x][j] && graph[y][j])
					{
						tri = true;

						break;
					}
				}
			}

			graph[x][y] = true;
			graph[y][x] = true;
		}

		max = 0;

		for (i = 1; i <= n; i++)
		{
			if (degree[i] > max)
			{
				max = degree[i];
			}
		}

		if (max < 3 && tri)
		{
			max = 3;
		}

		printf("%d\n", max);
	}

	return 0;
}