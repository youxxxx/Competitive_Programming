#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
	int n;
	int table[17][17];

	//freopen("input.txt", "r", stdin);

	memset(table, -1, sizeof(table));

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int num;

		scanf("%d", &num);

		for (int j = 0; j < num; j++)
		{
			int a, b;

			scanf("%d %d", &a, &b);

			table[i][a] = b;
		}
	}

	int ub;

	ub = (int)pow(2.0, n);

	int lmax = 0;

	for (int i = 0; i < ub; i++)
	{
		int truth[17];
		int cnt = 0;

		int temp;

		temp = i;

		for (int j = 1; j <= n; j++)
		{
			truth[j] = temp % 2;

			cnt += temp % 2;

			temp /= 2;

		}

		bool valid = true;

		for (int j = 1; j <= n; j++)
		{
			if (truth[j])
			{
				for (int k = 1; k <= n; k++)
				{
					if (table[j][k]!=-1 && truth[k] != table[j][k])
					{
						valid = false;

						break;
					}
				}
			}

			if (!valid)
			{
				break;
			}
		}

		/*
		if (valid)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= n; k++)
				{
					if (!truth[j])
					{
						if (truth[k] && table[k][j] != -1 && table[k][j])
						{
							valid = false;

							break;
						}
					}
				}

				if (!valid)
				{
					break;
				}
			}
		}
		*/

		if (valid&&cnt > lmax)
		{
			lmax = cnt;
		}
	}

	printf("%d\n", lmax);

	return 0;
}