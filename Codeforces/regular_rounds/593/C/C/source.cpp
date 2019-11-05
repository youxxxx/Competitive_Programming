#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int mat[300][300];
	int i, j;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		if (i % 2)
		{
			for (j = 0; j < n; j++)
			{
				mat[j][(j + i) % n] = i*n + j + 1;
			}
		}

		else
		{
			for (j = n - 1; j >= 0; j--)
			{
				mat[j][(j + i) % n] = i*n + n - j;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", mat[i][j]);
		}

		printf("\n");
	}

	return 0;
}