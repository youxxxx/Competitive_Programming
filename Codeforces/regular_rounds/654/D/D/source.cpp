#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, k;

		scanf("%d %d", &n, &k);

		int val1 = 999999999, val2 = 999999999;

		int grid1[300][300];
		int grid2[300][300];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				grid1[i][j] = grid2[i][j] = 0;
			}
		}

		{
			const int q = k / n;
			const int r = k%n;
			int left = k;

			for (int i = 0; i < n; i++)
			{
				int loop = q;

				if (i < r)
				{
					loop++;
				}

				for (int j = 0; j < loop; j++)
				{
					grid1[i][(j + i) % n] = 1;
				}

				left -= loop;
			}
			int rmin = 300, rmax = 0, cmin = 300, cmax = 0;

			for (int i = 0; i < n; i++)
			{
				int cnt = 0;

				for (int j = 0; j < n; j++)
				{
					cnt += grid1[i][j];
				}

				if (cnt < rmin)
				{
					rmin = cnt;
				}

				if (cnt > rmax)
				{
					rmax = cnt;
				}

				cnt = 0;

				for (int j = 0; j < n; j++)
				{
					cnt += grid1[j][i];
				}

				if (cnt < cmin)
				{
					cmin = cnt;
				}

				if (cnt > cmax)
				{
					cmax = cnt;
				}
			}

			val1 = (rmax - rmin)*(rmax - rmin) + (cmax - cmin)*(cmax - cmin);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				grid2[i][j] = 0;
			}
		}

		{
			const int q = k / n + 1;
			int left = k;

			for (int i = 0; i < n; i++)
			{
				int loop = left < q ? left : q;

				for (int j = 0; j < loop; j++)
				{
					grid2[i][(j + i) % n] = 1;
				}

				left -= loop;
			}
			int rmin = 300, rmax = 0, cmin = 300, cmax = 0;

			for (int i = 0; i < n; i++)
			{
				int cnt = 0;

				for (int j = 0; j < n; j++)
				{
					cnt += grid2[i][j];
				}

				if (cnt < rmin)
				{
					rmin = cnt;
				}

				if (cnt > rmax)
				{
					rmax = cnt;
				}

				cnt = 0;

				for (int j = 0; j < n; j++)
				{
					cnt += grid2[j][i];
				}

				if (cnt < cmin)
				{
					cmin = cnt;
				}

				if (cnt > cmax)
				{
					cmax = cnt;
				}
			}

			val2 = (rmax - rmin)*(rmax - rmin) + (cmax - cmin)*(cmax - cmin);
		}

		if (val1 < val2)
		{
			printf("%d\n", val1);

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					printf("%d", grid1[i][j]);
				}

				printf("\n");
			}
		}

		else
		{
			printf("%d\n", val2);

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					printf("%d", grid2[i][j]);
				}

				printf("\n");
			}
		}
	}

	return 0;
}