#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	int i, j, k;
	vector<pair<int, int>> sol;
	int mat[51][51];
	int res[51][51] = { 0, };
	int dx[4] = { 0,0,1,1 };
	int dy[4] = { 0,1,0,1 };

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}

	for (i = 1; i < n; i++)
	{
		for (j = 1; j < m; j++)
		{
			for (k = 0; k < 4; k++)
			{
				if (mat[i + dx[k]][j + dy[k]] == 0)
				{
					break;
				}
			}

			if (k == 4)
			{
				sol.push_back(make_pair(i, j));

				for (k = 0; k < 4; k++)
				{
					res[i + dx[k]][j + dy[k]] = 1;
				}
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (mat[i][j] != res[i][j])
			{
				printf("-1\n");

				return 0;
			}
		}
	}

	printf("%d\n", sol.size());

	for (i = 0; i < sol.size(); i++)
	{
		printf("%d %d\n", sol[i].first, sol[i].second);
	}

	return 0;
}