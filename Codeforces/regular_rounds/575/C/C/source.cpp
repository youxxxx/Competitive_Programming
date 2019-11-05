#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases, tc;
	vector<int> bound[4];
	int realb[4];
	int param[6];
	int cnt;
	int n;
	int i, j;
	int dir[4] = { 0,3,1,2 };

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d", &n);

		for (i = 0; i < 4; i++)
		{
			bound[i].clear();
		}

		for (i = 0; i < n; i++)
		{
			cnt = 0;

			for (j = 0; j < 2; j++)
			{
				scanf("%d", &param[j]);
			}

			for (j = 2; j < 6; j++)
			{
				scanf("%d", &param[j]);

				cnt += !!param[j];

				if (!param[j])
				{
					bound[dir[j - 2]].push_back(param[dir[(j - 2)] / 2]);
				}
			}
		}

		realb[0] = -100000;
		realb[1] = 100000;
		realb[2] = -100000;
		realb[3] = 100000;

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < bound[i].size(); j++)
			{
				if (!(i % 2))
				{
					if (bound[i][j] > realb[i])
					{
						realb[i] = bound[i][j];
					}
				}

				else
				{
					if (bound[i][j] < realb[i])
					{
						realb[i] = bound[i][j];
					}
				}
			}
		}

		for (i = 0; i < 2; i++)
		{
			if (realb[i * 2] > realb[i * 2 + 1])
			{
				break;
			}
		}

		if (i != 2)
		{
			printf("0\n");
		}
		
		else
		{
			printf("1 %d %d\n", realb[0], realb[2]);
		}
	}

	return 0;
}