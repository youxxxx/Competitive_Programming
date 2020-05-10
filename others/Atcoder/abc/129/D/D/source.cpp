#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	vector<string> arr;
	string str;
	char input[4000];
	int i, j;
	int left[2000][2000], right[2000][2000], up[2000][2000], down[2000][2000];
	int lmax = 0;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);
	
	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		str = input;

		arr.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		if (arr[i][0] == '#')
		{
			left[i][0] = 0;
		}

		else
		{
			left[i][0] = 1;
		}

		for (j = 1; j < m; j++)
		{
			if (arr[i][j] == '#')
			{
				left[i][j] = 0;
			}

			else
			{
				left[i][j] = left[i][j - 1] + 1;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		if (arr[i][m - 1] == '#')
		{
			right[i][m - 1] = 0;
		}

		else
		{
			right[i][m - 1] = 1;
		}

		for (j = 1; j < m; j++)
		{
			if (arr[i][m - j - 1] == '#')
			{
				right[i][m - j - 1] = 0;
			}

			else
			{
				right[i][m - j - 1] = right[i][m - j] + 1;
			}
		}
	}

	for (i = 0; i < m; i++)
	{
		if (arr[0][i] == '#')
		{
			up[0][i] = 0;
		}

		else
		{
			up[0][i] = 1;
		}

		for (j = 1; j < n; j++)
		{
			if (arr[j][i] == '#')
			{
				up[j][i] = 0;
			}

			else
			{
				up[j][i] = up[j - 1][i] + 1;
			}
		}
	}

	for (i = 0; i < m; i++)
	{
		if (arr[n - 1][i] == '#')
		{
			down[n - 1][i] = 0;
		}

		else
		{
			down[n - 1][i] = 1;
		}

		for (j = 1; j < n; j++)
		{
			if (arr[n - j - 1][i] == '#')
			{
				down[n - j - 1][i] = 0;
			}

			else
			{
				down[n - j - 1][i] = down[n - j][i] + 1;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (arr[i][j] != '#' && left[i][j] + right[i][j] + up[i][j] + down[i][j] - 3 > lmax)
			{
				lmax = left[i][j] + right[i][j] + up[i][j] + down[i][j] - 3;
			}
		}
	}

	printf("%d\n", lmax);

	return 0;
}