#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>

#define MOD 1000000007

using namespace std;

int main()
{
	int n, m;
	vector<int> r, c;
	int i, j;
	int cell[1000][1000];
	int input;
	long long res = 1;

	memset(cell , -1, sizeof(cell));

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		for (j = 0; j < input; j++)
		{
			if (cell[i][j] == 0)
			{
				printf("0\n");

				return 0;
			}

			cell[i][j] = 1;
		}

		if (input < m)
		{
			if (cell[i][input] == 1)
			{
				printf("0\n");

				return 0;
			}

			cell[i][input] = 0;
		}
	}

	for (i = 0; i < m; i++)
	{
		scanf("%d", &input);

		for (j = 0; j < input; j++)
		{
			if (cell[j][i] == 0)
			{
				printf("0\n");

				return 0;
			}

			cell[j][i] = 1;
		}

		if (input < n)
		{
			if (cell[input][i] == 1)
			{
				printf("0\n");

				return 0;
			}

			cell[input][i] = 0;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (cell[i][j] == -1)
			{
				res = (res * 2) % MOD;
			}
		}
	}

	printf("%lld\n", res);

	return 0;
}