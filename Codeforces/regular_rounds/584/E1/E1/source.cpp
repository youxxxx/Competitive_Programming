#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<functional>

using namespace std;

bool func(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first > b.first;
}

int main()
{
	int tc, cases;

	int arr[12][2000];
	int n, m;
	int i, j, k;
	vector<int> val;
	vector<pair<int, int>> col;
	int lmax[2000] = { 0, };
	int rot[4][4];
	int move[4] = { 0, };
	int rowmax[4];
	int ub;
	int sol = 0, cand;
	int reels;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		val.clear();
		col.clear();

		scanf("%d %d", &n, &m);

		memset(lmax, 0, sizeof(lmax));
		memset(move, 0, sizeof(move));


		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				scanf("%d", &arr[i][j]);

				val.push_back(arr[i][j]);

				if (arr[i][j] > lmax[j])
				{
					lmax[j] = arr[i][j];
				}
			}
		}

		for (i = 0; i < m; i++)
		{
			col.push_back(make_pair(lmax[i], i));
		}

		sort(val.begin(), val.end(), greater<int>());
		sort(col.begin(), col.end(), func);

		if (n == 1)
		{
			printf("%d\n", val[0]);

			continue;
		}

		if (n == 2)
		{
			printf("%d\n", val[0] + val[1]);

			continue;
		}

		reels = n < m ? n : m;

		for (i = 0; i < reels; i++)
		{
			for (j = 0; j < n; j++)
			{
				rot[j][i] = arr[j][col[i].second];
			}
		}

		sol = 0;
		
		ub = (int)pow(n, reels);

		for (i = 0; i < 4; i++)
		{
			move[i] = 0;
		}

		for (i = 0; i < ub; i++)
		{
			for (j = 0; j < n; j++)
			{
				rowmax[j] = 0;
			}

			for (j = 0; j < n; j++)
			{
				for (k = 0; k < reels; k++)
				{
					if (rot[(move[k] + j) % n][k] > rowmax[j])
					{
						rowmax[j] = rot[(move[k] + j) % n][k];
					}
				}
			}

			cand = 0;

			for (j = 0; j < n; j++)
			{
				cand += rowmax[j];
			}

			if (cand > sol)
			{
				sol = cand;
			}

			move[reels - 1]++;

			for (j = reels - 1; j >= 1; j--)
			{
				move[j - 1] += move[j] / n;
				move[j] %= n;
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}