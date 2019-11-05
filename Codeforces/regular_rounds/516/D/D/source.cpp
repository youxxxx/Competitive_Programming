#include<cstdio>
#include<string>
#include<queue>

using namespace std;

int main()
{
	int n, m;
	int r, c;
	int x, y;
	char input[2001];
	string maze[2000];
	int i, j;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	pair<pair<int, int>, pair<int, int>> cur;
	pair<int, int> coord, res;
	pair<int, int> next_c, next_r;
	int row, col;
	int left, right;
	int cnt = 0;

	scanf("%d %d", &n, &m);
	scanf("%d %d", &r, &c);
	scanf("%d %d", &x, &y);

	r--;
	c--;

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		maze[i] = input;
	}

	coord.first = r;
	coord.second = c;
	res.first = x;
	res.second = y;

	q.push(pair<pair<int, int>, pair<int, int>>(coord, res));

	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		coord = cur.first;
		res = cur.second;

		row = coord.first;
		col = coord.second;
		left = res.first;
		right = res.second;

		if (maze[row][col] != '.')
		{
			continue;
		}

		for (i = row; i >= 0 && maze[i][col] != '*'; i--)
		{
			maze[i][col] = ' ';

			if (left > 0 && col > 0 && maze[i][col - 1] == '.')
			{
				next_c.first = i;
				next_c.second = col - 1;
				next_r.first = left - 1;
				next_r.second = right;

				q.push(pair<pair<int, int>, pair<int, int>>(next_c, next_r));
			}

			if (right > 0 && col < m && maze[i][col + 1] == '.')
			{
				next_c.first = i;
				next_c.second = col + 1;
				next_r.first = left;
				next_r.second = right - 1;

				q.push(pair<pair<int, int>, pair<int, int>>(next_c, next_r));
			}
		}

		for (i = row + 1; i < n && maze[i][col] != '*'; i++)
		{
			maze[i][col] = ' ';

			if (left > 0 && col > 0 && maze[i][col - 1] == '.')
			{
				next_c.first = i;
				next_c.second = col - 1;
				next_r.first = left - 1;
				next_r.second = right;

				q.push(pair<pair<int, int>, pair<int, int>>(next_c, next_r));
			}

			if (right > 0 && col < m && maze[i][col + 1] == '.')
			{
				next_c.first = i;
				next_c.second = col + 1;
				next_r.first = left;
				next_r.second = right - 1;

				q.push(pair<pair<int, int>, pair<int, int>>(next_c, next_r));
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (maze[i][j] == ' ')
			{
				cnt++;
			}
		}
	}

	printf("%d", cnt);

	return 0;
}