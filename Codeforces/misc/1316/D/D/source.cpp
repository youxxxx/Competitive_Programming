#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n;

bool safe(int x, int y)
{
	return x >= 0 && x < n&&y >= 0 && y < n;
}

int main()
{
	pair<int, int> target[1000][1000];
	const int dx[4] = { -1,0,0,1 };
	const int dy[4] = { 0,-1,1,0 };
	char dir[4] = { 'D','R','L','U' };
	char ndir[4] = { 'U','L','R','D' };
	vector<string> sol;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
	{
		string part;

		for (int j = 0; j < n; j++)
		{
			int x, y;

			scanf("%d %d", &x, &y);

			target[i][j] = { --x, --y };

			if (x == i&&y == j)
			{
				q.push({ x,y });

				part.push_back('X');
			}

			else
			{
				part.push_back('O');
			}
		}

		sol.push_back(part);
	}

	while (!q.empty())
	{
		int x, y;

		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx, ny;

			nx = x + dx[i];
			ny = y + dy[i];

			if (safe(nx, ny) && sol[nx][ny]=='O' && target[nx][ny].first==target[x][y].first&&target[nx][ny].second==target[x][y].second)
			{
				sol[nx][ny] = dir[i];

				q.push({ nx,ny });
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (sol[i][j] == 'O')
			{
				if (target[i][j].first != -2)
				{
					printf("INVALID\n");

					return 0;
				}

				int nx, ny;

				bool found = false;

				for (int k = 0; k < 4; k++)
				{
					nx = i + dx[k];
					ny = j + dy[k];

					if (safe(nx, ny) && target[nx][ny].first == -2)
					{
						sol[i][j] = ndir[k];

						found = true;

						break;
					}
				}

				if (!found)
				{
					printf("INVALID\n");

					return 0;
				}
			}
		}
	}

	printf("VALID\n");

	for (int i = 0; i < n; i++)
	{
		printf("%s\n", sol[i].c_str());
	}

	return 0;
}