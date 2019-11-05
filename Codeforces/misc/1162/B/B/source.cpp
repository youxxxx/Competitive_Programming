#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int n, m;
	vector<long long> cur;
	vector<vector<long long>> mat[2];
	long long input, temp;
	int i, j;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		cur.clear();

		for (j = 0; j < m; j++)
		{
			scanf("%I64d", &input);

			cur.push_back(input);
		}

		mat[0].push_back(cur);
	}

	for (i = 0; i < n; i++)
	{
		cur.clear();

		for (j = 0; j < m; j++)
		{
			scanf("%I64d", &input);

			cur.push_back(input);
		}

		mat[1].push_back(cur);
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (mat[0][i][j] > mat[1][i][j])
			{
				temp = mat[0][i][j];
				mat[0][i][j] = mat[1][i][j];
				mat[1][i][j] = temp;
			}
		}
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (mat[0][i][j] >= mat[0][i + 1][j] || mat[1][i][j] >= mat[1][i + 1][j])
			{
				printf("Impossible\n");

				return 0;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m - 1; j++)
		{
			if (mat[0][i][j] >= mat[0][i][j + 1] || mat[1][i][j] >= mat[1][i][j + 1])
			{
				printf("Impossible\n");

				return 0;
			}
		}
	}

	printf("Possible\n");

	return 0;
}