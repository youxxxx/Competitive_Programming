#include<cstdio>
#include<cmath>
#include<queue>
#include<string>

using namespace std;

bool safe(int row, int col, int n, int m)
{
	return row >= 0 && row < n && col >= 0 && col < m;
}

int main()
{
	int n, m, p;
	long long speed[10];
	queue<pair<int, int>> q[10][2];
	vector<string> str;
	string input2;
	bool visited[1001][1001] = { false, };
	bool active[10];
	int cnt = 0;
	int tot[10];
	int turn = 1;
	int toggle[10];
	char input[1001];
	int i, j;
	long long z;
	int dx[4] = { 0,-1,0,1 };
	int dy[4] = { -1,0,1,0 };
	pair<int, int> cur;
	int row, col;
	int nrow, ncol;

	scanf("%d %d %d", &n, &m, &p);

	for (i = 1; i <= p; i++)
	{
		scanf("%I64d", &speed[i]);

		active[i] = true;

		toggle[i] = 1;

		tot[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		input2 = input;

		str.push_back(input2);

		for (j = 0; j < m; j++)
		{
			if (str[i][j] >= '1'&&str[i][j] <= '9')
			{
				q[str[i][j] - '0'][0].push(pair<int, int>(i, j));

				visited[i][j] = true;
			}

			else if (str[i][j] == '#')
			{
				visited[i][j] == true;
			}
		}
	}

	while (cnt != n)
	{
		if (!active[turn])
		{
			cnt++;


			turn = (turn + 1) % (p + 1);
			turn += !turn;

			continue;
		}

		if (q[turn][!toggle[turn]].empty())
		{
			active[turn] = false;


			turn = (turn + 1) % (p + 1);
			turn += !turn;

			continue;
		}

		cnt = 0;

		for (z = 0; z < speed[turn]; z++)
		{
			if (q[turn][!toggle[turn]].empty())
			{
				break;
			}

			while (!q[turn][!toggle[turn]].empty())
			{
				cur = q[turn][!toggle[turn]].front();

				q[turn][!toggle[turn]].pop();

				row = cur.first;
				col = cur.second;

				for (i = 0; i < 4; i++)
				{
					nrow = row + dx[i];
					ncol = col + dy[i];

					if (safe(nrow, ncol, n, m) && !visited[nrow][ncol] && str[nrow][ncol] == '.')
					{
						q[turn][toggle[turn]].push(pair<int, int>(nrow, ncol));

						str[nrow][ncol] = turn + '0';

						visited[nrow][ncol] = true;
					}
				}
			}

			toggle[turn] = !toggle[turn];
		}

		turn = (turn + 1) % (p + 1);
		turn += !turn;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (str[i][j] != '#')
			{
				tot[str[i][j] - '0']++;
			}
		}
	}

	for (i = 1; i <= p; i++)
	{
		printf("%d ", tot[i]);
	}

	return 0;
}