#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>

using namespace std;

int safe(int x, int n)
{
	return x >= 0 && x < n;
}

int main()
{
	int n, m, q;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &n, &m, &q);
	
	vector<string> arr(501);

	for (int i = 0; i < n; i++)
	{
		char input[501];
		string str;

		scanf("%s", input);
		str = input;

		arr[i] = str;
	}

	if (n < 2 || m < 2)
	{
		for (int i = 0; i < q; i++)
		{
			int r1, c1, r2, c2;

			scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

			printf("0\n");
		}

		return 0;
	}

	int square[500][500] = { 0, };
	int acc[251][501][501];

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			if (arr[i][j] == 'R'&&arr[i][j + 1] == 'G'&&arr[i + 1][j] == 'Y'&&arr[i + 1][j + 1] == 'B')
			{
				int l, r, u, d;
				int cnt = 1;

				u = i;
				d = i + 1;
				l = j;
				r = j + 1;

				while(1)
				{
					u--;
					d++;
					l--;
					r++;

					if (!safe(u, n) || !safe(d, n) || !safe(l, m) || !safe(r, m))
					{
						break;
					}

					bool valid = true;

					for (int k = l; k <= j; k++)
					{
						if (arr[u][k] != 'R')
						{
							valid = false;

							break;
						}
					}

					if (!valid)
					{
						break;
					}

					for (int k = u; k <= i; k++)
					{
						if (arr[k][l] != 'R')
						{
							valid = false;

							break;
						}
					}

					if (!valid)
					{
						break;
					}

					for (int k = j + 1; k <= r; k++)
					{
						if (arr[u][k] != 'G')
						{
							valid = false;

							break;
						}
					}

					if (!valid)
					{
						break;
					}

					for (int k = u; k <= i; k++)
					{
						if (arr[k][r] != 'G')
						{
							valid = false;

							break;
						}
					}

					if (!valid)
					{
						break;
					}

					for (int k = l; k <= j; k++)
					{
						if (arr[d][k] != 'Y')
						{
							valid = false;

							break;
						}
					}

					if (!valid)
					{
						break;
					}

					for (int k = i + 1; k <= d; k++)
					{
						if (arr[k][l] != 'Y')
						{
							valid = false;

							break;
						}
					}

					if (!valid)
					{
						break;
					}

					for (int k = j + 1; k <= r; k++)
					{
						if (arr[d][k] != 'B')
						{
							valid = false;

							break;
						}
					}

					if (!valid)
					{
						break;
					}

					for (int k = i + 1; k <= d; k++)
					{
						if (arr[k][r] != 'B')
						{
							valid = false;

							break;
						}
					}

					if (!valid)
					{
						break;
					}

					cnt++;
				}

				square[i][j] = cnt;
			}
		}
	}

	for (int k = 1; k <= n / 2; k++)
	{
		for (int j = 0; j <= m; j++)
		{
			acc[k][0][j] = 0;
		}

		for (int i = 1; i <= n; i++)
		{
			int rowacc = 0;

			acc[k][i][0] = 0;
			
			for (int j = 1; j <= m; j++)
			{
				int add = 0;

				if (square[i - 1][j - 1] >= k)
				{
					add = 1;
				}

				rowacc += add;

				acc[k][i][j] = acc[k][i - 1][j] + rowacc;
			}
		}
	}

	for (int i = 0; i < q; i++)
	{
		int r1, c1, r2, c2;

		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

		if (r1 == r2 || c1 == c2)
		{
			printf("0\n");

			continue;
		}

		int maxsize;

		maxsize = (r2 - r1 + 1) / 2 < (c2 - c1 + 1) / 2 ? (r2 - r1 + 1) / 2 : (c2 - c1 + 1) / 2;

		int lb, ub;

		lb = 0;
		ub = maxsize + 1;

		for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
		{
			int nl, nr, nu, nd;

			nl = c1 - 2 + next;
			nr = c2 - next;
			nu = r1 - 2 + next;
			nd = r2 - next;

			int val;

			val = acc[next][nd][nr] - acc[next][nu][nr] - acc[next][nd][nl] + acc[next][nu][nl];

			if (val)
			{
				lb = next;
			}

			else
			{
				ub = next;
			}
		}

		printf("%d\n", lb * lb * 4);
	}

	return 0;
}