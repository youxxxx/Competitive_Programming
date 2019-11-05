#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	int i, j;
	vector<int> rk[101];
	int cnt = 1;
	int a, b;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);

		rk[a].push_back(i);
		rk[b].push_back(i);
	}

	for (i = 1; i <= n; i++)
	{
		if (rk[i].empty())
		{
			printf("1\n%d %d\n", i, m + cnt++);
		}

		else
		{
			printf("%d\n", rk[i].size());

			for (j = 0; j < rk[i].size(); j++)
			{
				printf("%d %d\n", i, rk[i][j]);
			}
		}
	}

	return 0;
}