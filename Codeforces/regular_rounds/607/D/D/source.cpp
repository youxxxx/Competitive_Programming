#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int cases;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		vector<string> grid;
		char input[61];
		string str;

		int n, m;

		scanf("%d %d", &n, &m);

		bool alla = true, allp = true;

		for (int i = 0; i < n; i++)
		{
			scanf("%s", input);

			str = input;

			for (int j = 0; j < m; j++)
			{
				if (str[j] == 'A')
				{
					allp = false;
				}

				else
				{
					alla = false;
				}
			}

			grid.push_back(str);
		}

		if (alla)
		{
			printf("0\n");

			continue;
		}

		if (allp)
		{
			printf("MORTAL\n");

			continue;
		}

		int rowsucc[61][61];
		int colsucc[61][61];

		for (int i = 0; i < n; i++)
		{
			int curval = 0;

			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == 'A')
				{
					curval++;
				}

				else
				{
					curval = 0;
				}

				rowsucc[i][j] = curval;
			}
		}

		for (int i = 0; i < m; i++)
		{
			int curval = 0;

			for (int j = 0; j < n; j++)
			{
				if (grid[j][i] == 'A')
				{
					curval++;
				}

				else
				{
					curval = 0;
				}

				colsucc[j][i] = curval;
			}
		}

		int lmin = 4;

		for (int i = 1; i < m - 1; i++)
		{
			if (grid[0][i] == 'A' || grid[n - 1][i] == 'A')
			{
				lmin = 3;
			}
		}

		for (int i = 1; i < n - 1; i++)
		{
			if (grid[i][0] == 'A' || grid[i][m - 1] == 'A')
			{
				lmin = 3;
			}
		}

		if (grid[0][0] == 'A' || grid[0][m - 1] == 'A' || grid[n - 1][0] == 'A' || grid[n - 1][m - 1] == 'A')
		{
			lmin = 2;
		}

		if (rowsucc[0][m - 1] == m || rowsucc[n - 1][m - 1] == m || colsucc[n - 1][0] == n || colsucc[n - 1][m - 1] == n)
		{
			lmin = 1;
		}

		for (int i = 1; i < n - 1; i++)
		{
			if (lmin > 2 && rowsucc[i][m - 1] == m)
			{
				lmin = 2;
			}
		}

		for (int i = 1; i < m - 1; i++)
		{
			if (lmin > 2 && colsucc[n - 1][i] == n)
			{
				lmin = 2;
			}
		}

		if (lmin <= 2)
		{
			printf("%d\n", lmin);

			continue;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					continue;
				}

				for (int k = 0; k < m - 1; k++)
				{
					if (rowsucc[i][k] == k + 1)
					{
						for (int l = k + 1; l < m; l++)
						{
							if (rowsucc[j][l] >= l - k)
							{
								if (l == m - 1 || rowsucc[i][m - 1] >= m - l - 1)
								{
									int cand = 3;

									if (i == 0 || i == n - 1)
									{
										cand = 2;
									}

									if (cand < lmin)
									{
										lmin = cand;
									}
								}
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i == j)
				{
					continue;
				}

				for (int k = 0; k < n - 1; k++)
				{
					if (colsucc[k][i] == k + 1)
					{
						for (int l = k + 1; l < n; l++)
						{
							if (colsucc[k][j] >= l - k)
							{
								if (l == n - 1 || colsucc[n - 1][i] >= n - l - 1)
								{
									int cand = 3;

									if (i == 0 || i == m - 1)
									{
										cand = 2;
									}

									if (cand < lmin)
									{
										lmin = cand;
									}
								}
							}
						}
					}
				}
			}
		}

		printf("%d\n", lmin);
	}

	return 0;
}