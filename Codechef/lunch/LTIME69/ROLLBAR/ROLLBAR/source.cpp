#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

bool field[1001][1001];

int safe(int x, int y, int n, int m, int blocktype)
{
	if (blocktype == 1)
	{
		return x > 0 && x + 1 <= n && y > 0 && y <= m && field[x][y] && field[x + 1][y];
	}

	if (blocktype == 2)
	{
		return x > 0 && x <= n && y > 0 && y + 1 <= m && field[x][y] && field[x][y + 1];
	}

	return x > 0 && x <= n && y > 0 && y <= m && field[x][y];
}

int main()
{
	int t, z;
	int **min[3];
	int n, m;
	int i, j;
	int x, y;
	char input[1001];

	pair<pair<int, int>, pair<int, int>> cur, next;
	queue<	pair<pair<int,int>, pair<int, int>>> q;

	//freopen("input.txt", "r", stdin);

	for (i = 0; i < 3; i++)
	{
		min[i] = new int*[1001];

		for (j = 1; j <= 1000; j++)
		{
			min[i][j] = new int[1001];
		}
	}

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &m);

		scanf("%d %d", &x, &y);

		for (i = 1; i <= n; i++)
		{
			scanf("%s", input);

			for (j = 1; j <= m; j++)
			{
				min[0][i][j] = min[1][i][j] = min[2][i][j] = -1;

				field[i][j] = (bool)(input[j - 1] - '0');
			}
		}

		min[0][x][y] = 0;

		cur.first.first = 0;
		cur.first.second = 0;
		cur.second.first = x;
		cur.second.second = y;

		q.push(cur);

		while (!q.empty())
		{
			cur = q.front();
			q.pop();
			x = cur.second.first;
			y = cur.second.second;

			switch (cur.first.second)
			{
			case 0:
				if (safe(x - 2, y, n, m, 1) && min[1][x - 2][y] == -1)
				{
					min[1][x - 2][y] = cur.first.first + 1;

					next.first.first = cur.first.first + 1;
					next.first.second = 1;
					next.second.first = x - 2;
					next.second.second = y;

					q.push(next);
				}

				if (safe(x + 1, y, n, m, 1) && min[1][x + 1][y] == -1)
				{
					min[1][x + 1][y] = cur.first.first + 1;

					next.first.first = cur.first.first + 1;
					next.first.second = 1;
					next.second.first = x + 1;
					next.second.second = y;

					q.push(next);
				}

				if (safe(x, y - 2, n, m, 2) && min[2][x][y - 2] == -1)
				{
					min[2][x][y - 2] = cur.first.first + 1;

					next.first.first = cur.first.first + 1;
					next.first.second = 2;
					next.second.first = x;
					next.second.second = y - 2;

					q.push(next);
				}

				if (safe(x, y + 1, n, m, 2) && min[2][x][y + 1] == -1)
				{
					min[2][x][y + 1] = cur.first.first + 1;

					next.first.first = cur.first.first + 1;
					next.first.second = 2;
					next.second.first = x;
					next.second.second = y + 1;

					q.push(next);
				}

				break;

			case 1:
				if (safe(x - 1, y, n, m, 0) && min[0][x - 1][y] == -1)
				{
					min[0][x - 1][y] = cur.first.first + 1;

					next.first.first = cur.first.first + 1;
					next.first.second = 0;
					next.second.first = x - 1;
					next.second.second = y;

					q.push(next);
				}

				if (safe(x + 2, y, n, m, 0) && min[0][x + 2][y] == -1)
				{
					min[0][x + 2][y] = cur.first.first + 1;

					next.first.first = cur.first.first + 1;
					next.first.second = 0;
					next.second.first = x + 2;
					next.second.second = y;

					q.push(next);
				}

				if (safe(x, y - 1, n, m, 1) && min[1][x][y - 1] == -1)
				{
					min[1][x][y - 1] = cur.first.first + 1;

					next.first.first = cur.first.first + 1;
					next.first.second = 1;
					next.second.first = x;
					next.second.second = y - 1;

					q.push(next);
				}

				if (safe(x, y + 1, n, m, 1) && min[1][x][y + 1] == -1)
				{
					min[1][x][y + 1] = cur.first.first + 1;

					next.first.first = cur.first.first + 1;
					next.first.second = 1;
					next.second.first = x;
					next.second.second = y + 1;

					q.push(next);
				}

				break;

			case 2:
				if (safe(x - 1, y, n, m, 2) && min[2][x - 1][y] == -1)
				{
					min[2][x - 1][y] = cur.first.first + 1;

					next.first.first = cur.first.first + 1;
					next.first.second = 2;
					next.second.first = x - 1;
					next.second.second = y;

					q.push(next);
				}

				if (safe(x + 1, y, n, m, 2) && min[2][x + 1][y] == -1)
				{
					min[2][x + 1][y] = cur.first.first + 1;

					next.first.first = cur.first.first + 1;
					next.first.second = 2;
					next.second.first = x + 1;
					next.second.second = y;

					q.push(next);
				}

				if (safe(x, y - 1, n, m, 0) && min[0][x][y - 1] == -1)
				{
					min[0][x][y - 1] = cur.first.first + 1;

					next.first.first = cur.first.first + 1;
					next.first.second = 0;
					next.second.first = x;
					next.second.second = y - 1;

					q.push(next);
				}

				if (safe(x, y + 2, n, m, 0) && min[0][x][y + 2] == -1)
				{
					min[0][x][y + 2] = cur.first.first + 1;

					next.first.first = cur.first.first + 1;
					next.first.second = 0;
					next.second.first = x;
					next.second.second = y + 2;

					q.push(next);
				}

				break;

			}
		}

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				printf("%d ", min[0][i][j]);
			}

			printf("\n");
		}
	}

	return 0;
}