#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, m, mod;

	scanf("%d %d %d", &n, &m, &mod);

	int arr[70][70];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	int lmax[2][70];

	memset(lmax, -1, sizeof(lmax));

	lmax[1][0] = 0;

	for (int i = 0; i < n; i++)
	{
		int dp[2][70][70];

		memset(dp, -1, sizeof(dp));

		dp[1][0][0] = 0;

		for (int l = 0; l < m; l++)
		{
			//memset(dp[l % 2], -1, sizeof(dp[l % 2]));

			for (int j = 0; j <= m / 2; j++)
			{
				for (int k = 0; k < mod; k++)
				{
					dp[l % 2][j][k] = dp[!(l % 2)][j][k];
				}
			}

			for (int j = 0; j < m / 2; j++)
			{
				for (int k = 0; k < mod; k++)
				{
					if (dp[!(l % 2)][j][k] != -1)
					{
						dp[l % 2][j + 1][(k + arr[i][l]) % mod] = max(dp[l % 2][j + 1][(k + arr[i][l]) % mod], dp[!(l % 2)][j][k] + arr[i][l]);
					}
				}
			}
		}

		int modmax[70] = { 0, };

		for (int j = 0; j < mod; j++)
		{
			for (int k = 0; k <= m / 2; k++)
			{
				modmax[j] = max(modmax[j], dp[!(m % 2)][k][j]);
			}
		}

		memset(lmax[i % 2], -1, sizeof(lmax[i % 2]));

		for (int j = 0; j < mod; j++)
		{
			for (int k = 0; k < mod; k++)
			{
				if (lmax[!(i % 2)][j] != -1)
				{
					lmax[i % 2][(j + k) % mod] = max(lmax[i % 2][(j + k) % mod], lmax[!(i % 2)][j] + modmax[k]);
				}
			}
		}
	}

	printf("%d\n", lmax[!(n % 2)][0]);

	return 0;
}