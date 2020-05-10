#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>

#define MOD 1000000007

using namespace std;

int main()
{
	int n, m;
	int a[80][80], b[80][80];
	set<int> list[80][80];
	int val[80][80];

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			val[i][j] = abs(a[i][j] - b[i][j]);
		}
	}

	list[0][0].insert(val[0][0]);
	list[0][0].insert(-val[0][0]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			set<int>::iterator it;

			int left;

			if (i - 1 >= 0)
			{
				for (it = list[i - 1][j].begin(); it != list[i - 1][j].end(); it++)
				{
					if (abs(*it + val[i][j]) <= 6561)
					{
						list[i][j].insert(*it + val[i][j]);
					}

					if (abs(*it - val[i][j]) <= 6561)
					{
						list[i][j].insert(*it - val[i][j]);
					}
				}
			}

			if (j - 1 >= 0)
			{
				for (it = list[i][j - 1].begin(); it != list[i][j - 1].end(); it++)
				{
					if (abs(*it + val[i][j]) <= 6561)
					{
						list[i][j].insert(*it + val[i][j]);
					}

					if (abs(*it - val[i][j]) <= 6561)
					{
						list[i][j].insert(*it - val[i][j]);
					}
				}
			}
		}
	}

	int lmin = 999999999;

	set<int>::iterator it;

	for (it = list[n - 1][m - 1].begin(); it != list[n - 1][m - 1].end(); it++)
	{
		if (abs(*it) < lmin)
		{
			lmin = abs(*it);
		}
	}

	printf("%d\n", lmin);

	return 0;
}