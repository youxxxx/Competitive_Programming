#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<cstring>
#include<map>
#include<set>
#include<stack>

using namespace std;

int main()
{
	int n, h, l, r;
	int dp[2][2001];

	scanf("%d %d %d %d", &n, &h, &l, &r);

	memset(dp, -1, sizeof(dp));

	dp[1][0] = 0;

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		for (int j = 0; j < n; j++)
		{
			dp[i % 2][j] = -1;
		}

		for (int j = 0; j < h; j++)
		{
			if (dp[!(i % 2)][j] != -1)
			{
				int next;

				next = (j + input) % h;

				int cand;

				cand = dp[!(i % 2)][j];

				if (next >= l&&next <= r)
				{
					cand++;
				}

				if (cand > dp[i % 2][next])
				{
					dp[i % 2][next] = cand;
				}

				next = (j + input - 1) % h;

				cand = dp[!(i % 2)][j];

				if (next >= l&&next <= r)
				{
					cand++;
				}

				if (cand > dp[i % 2][next])
				{
					dp[i % 2][next] = cand;
				}
			}
		}
	}

	int lmax = 0;

	for (int i = 0; i < h; i++)
	{
		if (dp[!(n % 2)][i] > lmax)
		{
			lmax = dp[!(n % 2)][i];
		}
	}

	printf("%d\n", lmax);

	return 0;
}
