#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>

#define MOD 998244353

using namespace std;

int main()
{
	int row[10000];
	int col[100];
	int sol[100][100], sol2[100][100];
	int left[100];
	int n, m;
	int i, j, k;
	int input;
	int temp, cur;

	scanf("%d %d", &n, &m);

	memset(sol, -1, sizeof(sol));

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &input);

			input--;

			row[input] = i;
		}

		left[i] = m;
	}

	for (j = 0; j < m; j++)
	{
		col[j] = j;

		sol[row[j]][j] = j;

		left[row[j]]--;
	}

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			col[j] = -1;
		}

		for (j = 0; j < m; j++)
		{
			if (sol[row[i*m + j]][j] == -1 && col[j] == -1)
			{
				sol[row[i*m + j]][j] = i*m + j;

				col[j] = j;
			}

			else
			{
				for (k = 0; k < m; k++)
				{
					if (sol[row[i*m + j]][k] == -1 && col[k] == -1)
					{
						col[k] = j;

						sol[row[i*m + j]][k] = i*m + j;
					}
				}
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", sol[i][j] + 1);
		}

		printf("\n");
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			temp = sol[i][j];

			sol2[temp / m][j] = temp;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", sol2[i][j] + 1);
		}

		printf("\n");
	}

	return 0;
}