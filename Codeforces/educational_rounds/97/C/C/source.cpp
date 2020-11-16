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

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		int arr[201];

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);
		}

		sort(&arr[1], &arr[n + 1]);

		int dp[201][500] = { 0, };

		memset(dp, -1, sizeof(dp));

		dp[0][0] = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n + i + 1; j++)
			{
				dp[i][j] = 1000000000;

				for (int k = 0; k < j; k++)
				{
					if (dp[i - 1][k] != -1)
					{
						dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(j - arr[i]));
					}
				}
			}
		}

		int sol = 1000000000;

		for (int i = n; i <= n * 2 + 1; i++)
		{
			if (dp[n][i] != -1)
			{
				sol = min(sol, dp[n][i]);
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}