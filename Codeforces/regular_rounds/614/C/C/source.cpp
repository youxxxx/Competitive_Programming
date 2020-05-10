#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

int n, q;

int safe(int x, int y)
{
	return (x == 1 || x == 2) && y >= 1 && y <= n;
}

int main()
{
	int cell[3][100001] = { 0, };
	int state[3][100001] = { 0, };
	int cnt = 0;
	const int dx[9] = { -1,-1,-1,0,0,0,1,1,1 };
	const int dy[9] = { -1,0,1,-1,0,1,-1,0,1 };
	const int dy2[3] = { -1,0,1 };

	scanf("%d %d", &n, &q);

	for (int i = 0; i < q; i++)
	{
		int x, y;

		scanf("%d %d", &x, &y);

		cell[x][y] = !cell[x][y];

		for (int i = 0; i < 9; i++)
		{
			int nx, ny;

			nx = x + dx[i];
			ny = y + dy[i];

			if (safe(nx, ny))
			{
				int nextstate = 0;

				if (cell[nx][ny])
				{
					for (int j = 0; j < 3; j++)
					{
						int nx2, ny2;

						nx2 = 3 - nx;
						ny2 = ny + dy2[j];

						if (safe(nx2, ny2) && cell[nx2][ny2])
						{
							nextstate = 1;
						}
					}
				}

				cnt += nextstate - state[nx][ny];

				state[nx][ny] = nextstate;
			}
		}

		if (cnt)
		{
			printf("No\n");
		}

		else
		{
			printf("Yes\n");
		}
	}

	return 0;
}