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

using namespace std;

bool safe(int x, int y, int n, int m)
{
	return x >= 0 && y >= 0 && x < n&&y < m;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	const int dx[4] = { -1,1,0,0 };
	const int dy[4] = { 0,0,-1,1 };

	int cases;

	scanf("%d", &cases);

	for (int tc = 1; tc <= cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		vector<vector<long long>> arr;
		vector<vector<long long>> nthmark;

		vector < vector<vector<pair<int, int>>>> dir;
		vector<pair<int, int>> alive[2];

		long long tot = 0;

		for (int i = 0; i < n; i++)
		{
			vector < vector<pair<int, int>>> emp;

			vector<long long> cur;
			vector<long long> ncur;

			for (int j = 0; j < m; j++)
			{
				long long input;

				scanf("%lld", &input);

				cur.push_back(input);
				ncur.push_back(-1);

				tot += input;

				vector < pair<int, int>> four;

				for (int k = 0; k < 4; k++)
				{
					four.push_back({ i + dx[k],j + dy[k] });
				}

				emp.push_back(four);

				alive[0].push_back({ i,j });
			}

			dir.push_back(emp);
			arr.push_back(cur);
			nthmark.push_back(ncur);
		}
		int bit = 1;

		for (int i = 0; i < n; i++)
		{

			for (int j = 0; j < m; j++)
			{
			}
		}

		long long sol = 0;
		bool change;
		
		int loop = 0;

		do
		{
			change = false;

			alive[bit].clear();

			sol += tot;

			vector<pair<int, int>> temp;

			for (int z = 0; z < alive[!bit].size(); z++)
			{
				int i, j;

				i = alive[!bit][z].first;
				j = alive[!bit][z].second;

				long long sum = 0;
				long long cnt = 0;

				for (int k = 0; k < 4; k++)
				{
					int nx, ny;

					nx = dir[i][j][k].first;
					ny = dir[i][j][k].second;

					if (safe(nx, ny, n, m))
					{
						sum += arr[nx][ny];

						cnt++;
					}
				}

				if(!cnt || arr[i][j] * cnt >= sum)
				{
					//alive[bit].push_back({ i,j });
				}

				else
				{
					temp.push_back({ i,j });

					tot -= arr[i][j];

					change = true;
				}
			}

			for (int z = 0; z < temp.size(); z++)
			{
				int i, j;

				i = temp[z].first;
				j = temp[z].second;

				for (int k = 0; k < 4; k++)
				{
					int nx, ny;

					nx = dir[i][j][k].first;
					ny = dir[i][j][k].second;

					if (safe(nx, ny, n, m))
					{
						int mirror;

						mirror = k / 2 * 2 + !(k % 2);

						int ox, oy;

						ox = dir[i][j][mirror].first;
						oy = dir[i][j][mirror].second;

						dir[nx][ny][mirror] = { ox,oy };

						if (nthmark[nx][ny] != loop)
						{
							alive[bit].push_back({ nx,ny });

							nthmark[nx][ny] = loop;
						}
					}
				}
			}

			bit = !bit;

			loop++;
		} while (change);

		printf("Case #%d: %lld\n", tc, sol);
	}

	return 0;
}