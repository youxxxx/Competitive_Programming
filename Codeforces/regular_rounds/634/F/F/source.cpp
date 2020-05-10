#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

#define MAXN 200000
#define MAXA 200

using namespace std;

bool safe(int x, int y, int n, int m)
{
	return x >= 0 && x < n&&y >= 0 && y < m;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	const int dx[4] = { 0,0,-1,1 };
	const int dy[4] = { -1,1,0,0 };
	int lx[256] = { 0, };
	int ly[256] = { 0, };

	ly['L'] = -1;
	ly['R'] = 1;
	lx['U'] = -1;
	lx['D'] = 1;

	for (int tc = 0; tc < cases; tc++)
	{
		vector<string> color;
		vector<string> arr;
		vector<vector<int>> cycle;
		vector<vector<bool>> visited;
		vector<vector<bool>> visited2;

		int n, m;

		scanf("%d %d", &n, &m);

		vector<int> ivec;
		vector<bool> bvec;

		for (int i = 0; i < m; i++)
		{
			ivec.push_back(-1);
			bvec.push_back(false);
		}

		for (int i = 0; i < n; i++)
		{
			char input[1000001];
			string str;

			scanf("%s", input);
			str = input;

			color.push_back(str);

			cycle.push_back(ivec);
			visited.push_back(bvec);
			visited2.push_back(bvec);
		}

		for (int i = 0; i < n; i++)
		{
			char input[1000001];
			string str;

			scanf("%s", input);
			str = input;

			arr.push_back(str);
		}

		int tot = 0, black = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!visited2[i][j])
				{
					visited[i][j] = true;

					int curx, cury;

					cycle[i][j] = 0;

					curx = i + lx[arr[i][j]];
					cury = j + ly[arr[i][j]];

					int cnt = 1;

					while (!visited[curx][cury])
					{
						visited[curx][cury] = true;

						cycle[curx][cury] = cnt;

						int nx, ny;

						nx = curx + lx[arr[curx][cury]];
						ny = cury + ly[arr[curx][cury]];

						curx = nx;
						cury = ny;

						cnt++;
					}

					int len;

					len = cnt - cycle[curx][cury];

					tot += len;

					int x, y;

					x = curx;
					y = cury;

					stack<pair<pair<int, int>,int>> s;

					s.push({ { x,y },0 });

					vector<int> path;

					/*
					path.push_back(0);

					if (color[x][y] == '0')
					{
						path[0] = 1;

						black++;
					}
					*/

					visited2[x][y] = true;

					while (!s.empty())
					{
						int x, y, cnt;
						int nx, ny;

						x = s.top().first.first;
						y = s.top().first.second;
						cnt = s.top().second;

						s.pop();

						int nth;

						nth = cnt%len;

						if (path.size() <= nth)
						{
							path.push_back(0);

							if (color[x][y] == '0')
							{
								path.back() = 1;

								black++;
							}
						}

						else
						{
							if (color[x][y] == '0'&&path[nth] == 0)
							{
								path[nth] = 1;

								black++;
							}
						}

						for (int k = 0; k < 4; k++)
						{
							nx = x + dx[k];
							ny = y + dy[k];

							if (safe(nx, ny, n, m) && !visited2[nx][ny])
							{
								if (nx + lx[arr[nx][ny]] == x&&ny + ly[arr[nx][ny]] == y)
								{
									visited2[nx][ny] = true;

									s.push({ {nx,ny},cnt + 1 });
								}
							}
						}
					}
				}
			}
		}

		printf("%d %d\n", tot, black);
	}

	return 0;
}