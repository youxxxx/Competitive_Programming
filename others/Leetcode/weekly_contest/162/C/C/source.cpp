#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Solution
{
public:
	int areamap[101][101];
	int sol;
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };
	int ox[8] = { -1,0,1,-1,1,-1,0,1, };
	int oy[8] = { -1,-1,-1,0,0,1,1,1 };
	int n, m;

	int safe(int x, int y)
	{
		return x >= 0 && x < n&&y >= 0 && y < m;
	}

	Solution()
	{
		sol = 0;
	}

	void rec(int cur, int phase, int row, int col, vector<vector<int>>& grid)
	{
		stack<pair<int, int>> s, cand;

		sol += !phase;

		s.push(make_pair(row, col));

		areamap[row][col] = cur + 1;

		while (!s.empty())
		{
			int x, y;

			x = s.top().first;
			y = s.top().second;

			s.pop();

			if (phase)
			{
				for (int i = 0; i < 8; i++)
				{
					int nx, ny;

					nx = x + ox[i];
					ny = y + oy[i];

					if (safe(nx, ny))
					{
						if (areamap[nx][ny] == cur || areamap[nx][ny] == -1 && grid[nx][ny] == phase)
						{
							areamap[nx][ny] = cur + 1;

							s.push(make_pair(nx, ny));
						}

						else if (areamap[nx][ny] == -1 && grid[nx][ny] != phase)
						{
							areamap[nx][ny] = cur + 2;

							cand.push(make_pair(nx, ny));
						}
					}
				}
			}

			else
			{
				for (int i = 0; i < 4; i++)
				{
					int nx, ny;

					nx = x + dx[i];
					ny = y + dy[i];

					if (safe(nx, ny))
					{
						if (areamap[nx][ny] == cur || areamap[nx][ny] == -1 && grid[nx][ny] == phase)
						{
							areamap[nx][ny] = cur + 1;

							s.push(make_pair(nx, ny));
						}

						else if (areamap[nx][ny] == -1 && grid[nx][ny] != phase)
						{
							areamap[nx][ny] = cur + 2;

							cand.push(make_pair(nx, ny));
						}
					}
				}
			}
		}

		while (!cand.empty())
		{
			int x, y;

			x = cand.top().first;
			y = cand.top().second;

			cand.pop();

			if (areamap[x][y] == cur + 2)
			{
				rec(cur + 2, !phase, x, y, grid);
			}
		}
	}

	int closedIsland(vector<vector<int>>& grid)
	{
		n = grid.size();
		m = grid[0].size();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				areamap[i][j] = -1;
			}
		}

		for (int i = 0; i < n; i++)
		{
			stack<pair<int, int>> s;

			if (grid[i][0] == 0&&areamap[i][0]==-1)
			{
				areamap[i][0] = -2;

				int x, y;

				x = i;
				y = 0;

				s.push(make_pair(x, y));

				while (!s.empty())
				{
					x = s.top().first;
					y = s.top().second;

					s.pop();

					for (int i = 0; i < 4; i++)
					{
						int nx, ny;

						nx = x + dx[i];
						ny = y + dy[i];

						if (safe(nx, ny))
						{
							if (areamap[nx][ny] == -1 && grid[nx][ny] == 0)
							{
								areamap[nx][ny] = -2;

								s.push(make_pair(nx, ny));
							}
						}
					}
				}
			}

			if (grid[i][m - 1] == 0&& areamap[i][m - 1] == -1)
			{
				areamap[i][m - 1] = -2;

				int x, y;

				x = i;
				y = m - 1;

				s.push(make_pair(x, y));

				while (!s.empty())
				{
					x = s.top().first;
					y = s.top().second;

					s.pop();

					for (int i = 0; i < 4; i++)
					{
						int nx, ny;

						nx = x + dx[i];
						ny = y + dy[i];

						if (safe(nx, ny))
						{
							if (areamap[nx][ny] == -1 && grid[nx][ny] == 0)
							{
								areamap[nx][ny] = -2;

								s.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < m; i++)
		{
			stack<pair<int, int>> s;

			if (grid[0][i] == 0 && areamap[0][i] == -1)
			{
				areamap[0][i] = -2;
				int x, y;

				x = 0;
				y = i;

				s.push(make_pair(x, y));

				while (!s.empty())
				{
					x = s.top().first;
					y = s.top().second;

					s.pop();

					for (int i = 0; i < 4; i++)
					{
						int nx, ny;

						nx = x + dx[i];
						ny = y + dy[i];

						if (safe(nx, ny))
						{
							if (areamap[nx][ny] == -1 && grid[nx][ny] == 0)
							{
								areamap[nx][ny] = -2;

								s.push(make_pair(nx, ny));
							}
						}
					}
				}
			}

			if (grid[n - 1][i] == 0 && areamap[n - 1][i] == -1)
			{
				areamap[n - 1][i] = -2;
				int x, y;

				x = n - 1;
				y = i;

				s.push(make_pair(x, y));

				while (!s.empty())
				{
					x = s.top().first;
					y = s.top().second;

					s.pop();

					for (int i = 0; i < 4; i++)
					{
						int nx, ny;

						nx = x + dx[i];
						ny = y + dy[i];

						if (safe(nx, ny))
						{
							if (areamap[nx][ny] == -1 && grid[nx][ny] == 0)
							{
								areamap[nx][ny] = -2;

								s.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == 1 && areamap[i][j] == -1)
				{
					rec(0, 1, i, j, grid);
				}
			}
		}

		return sol;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> v = { { 0,1,0,1,0,0,0,1,1,0,1,1,0,0,1,1,1,0,1,1 },{ 0,1,1,0,0,0,0,1,1,1,0,1,0,1,1,0,0,1,0,1 },{ 1,1,0,1,0,0,1,1,1,0,0,0,1,0,0,1,0,1,0,0 },{ 0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0 },{ 1,1,0,0,1,0,0,1,1,0,1,1,0,1,1,1,0,0,1,1 },{ 1,1,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,0,0,1 },{ 1,0,1,1,0,1,0,1,0,0,1,0,1,1,1,1,1,0,1,0 },{ 1,0,0,1,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1 },{ 0,0,0,1,1,1,0,1,1,1,0,1,0,1,1,0,1,0,0,0 },{ 1,1,0,0,0,0,1,1,0,0,0,1,0,0,1,0,1,0,1,1 },{ 1,0,0,1,1,1,1,0,1,0,1,1,1,0,0,0,0,1,1,0 },{ 1,1,0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,1,1,1 },{ 0,1,1,0,0,1,1,0,0,1,0,1,1,1,1,1,1,0,0,0 },{ 1,0,0,0,1,1,0,1,1,1,0,0,1,0,1,1,0,1,0,1 } };

	s.closedIsland(v);

	return 0;
}