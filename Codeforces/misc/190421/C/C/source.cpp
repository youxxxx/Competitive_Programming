#include<cstdio>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	int t, z;
	int i, j, k;
	int n;
	int lmax;
	vector<vector<int>> idx[10];
	vector<int> cur;
	vector<int> q[2];
	int size[2];
	int ans;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		lmax = 0;

		idx[0].clear();
		cur.clear();

		for (i = 1; i <= n; i++)
		{
			cur.push_back(i);
		}

		idx[0].push_back(cur);

		for (i = 1; i <= 9; i++)
		{
			idx[i].clear();
			q[0].clear();
			q[1].clear();

			for (j = 0; j < idx[i - 1].size(); j++)
			{
				cur.clear();

				for (k = 0; k < idx[i - 1][j].size() / 2; k++)
				{
					cur.push_back(idx[i - 1][j][k]);

					q[0].push_back(idx[i - 1][j][k]);
				}

				idx[i].push_back(cur);

				cur.clear();

				for (k = idx[i - 1][j].size() / 2; k < idx[i - 1][j].size(); k++)
				{
					cur.push_back(idx[i - 1][j][k]);

					q[1].push_back(idx[i - 1][j][k]);
				}

				idx[i].push_back(cur);
			}

			if (q[0].empty())
			{
				break;
			}

			printf("%d %d", q[0].size(), q[1].size());

			for (j = 0; j < q[0].size(); j++)
			{
				printf(" %d", q[0][j]);
			}

			for (j = 0; j < q[1].size(); j++)
			{
				printf(" %d", q[1][j]);
			}

			printf("\n");
			fflush(stdout);

			scanf("%d", &ans);

			if (ans > lmax)
			{
				lmax = ans;
			}
		}

		printf("-1 %d\n", lmax);
		fflush(stdout);
	}

	return 0;
}