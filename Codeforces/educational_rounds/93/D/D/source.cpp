#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, m, l;

	scanf("%d %d %d", &n, &m, &l);

	long long a[201], b[201], c[201];

	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}

	sort(&a[1], &a[n + 1], greater<long long>());

	for (int i = 1; i <= m; i++)
	{
		scanf("%lld", &b[i]);
	}

	sort(&b[1], &b[m + 1], greater<long long>());

	for (int i = 1; i <= l; i++)
	{
		scanf("%lld", &c[i]);
	}

	sort(&c[1], &c[l + 1], greater<long long>());

	long long dp[201][201][201] = { 0, };
	long long sol = 0;
	int dx[3] = { 0,-1,-1 };
	int dy[3] = { -1,0,-1 };
	int dz[3] = { -1,-1,0 };

	for (int loop = 2; loop <= n + m + l; loop += 2)
	{
		for (int i = 0; i <= n && i <= loop; i++)
		{
			for (int j = 0; j <= m && i + j <= loop; j++)
			{
				const int k = loop - i - j;

				if (k > l)
				{
					continue;
				}

				{
					for (int dir = 0; dir < 3; dir++)
					{
						const int nx = i + dx[dir];
						const int ny = j + dy[dir];
						const int nz = k + dz[dir];

						if (nx >= 0 && ny >= 0 && nz >= 0)
						{
							long long ma = (-dx[dir])*a[i];
							ma += !ma;
							long long mb = (-dy[dir])*b[j];
							mb += !mb;
							long long mc = (-dz[dir])*c[k];
							mc += !mc;

							const long long cand = dp[nx][ny][nz] + (ma*mb*mc);

							if (cand > dp[i][j][k])
							{
								dp[i][j][k] = cand;
							}

							if (cand > sol)
							{
								sol = cand;
							}
						}
					}
				}
			}
		}
	}

	printf("%lld\n", sol);

	return 0;
}