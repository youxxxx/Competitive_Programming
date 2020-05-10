#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

#define NAN -999999999999999999

int main()
{
	//freopen("input.txt", "r", stdin);

	int n;

	scanf("%d", &n);

	vector<long long> arr(200001);

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	long long dp[200001][3];

	dp[0][0] = arr[0];
	dp[1][1] = arr[1];

	if (n >= 2)
	{
		dp[2][2] = arr[2];
		dp[2][0] = arr[0] + arr[2];
		dp[2][1] = NAN;
	}

	for (int i = 3; i < n; i++)
	{
		if (!(i % 2))
		{
			dp[i][0] = dp[i - 2][0] + arr[i];
			dp[i][1] = NAN;

			if (n % 2)
			{
				long long cand;

				cand = dp[i - 2][2];

				if (dp[i - 3][1] > cand)
				{
					cand = dp[i - 3][1];
				}

				if (i >= 4 && dp[i - 4][0] > cand)
				{
					cand = dp[i - 4][0];
				}

				dp[i][2] = cand + arr[i];
			}
		}

		else
		{
			dp[i][0] = dp[i][2] = NAN;

			long long cand;

			cand = dp[i - 2][1];

			if (dp[i - 3][0] > cand)
			{
				cand = dp[i - 3][0];
			}

			dp[i][1] = cand + arr[i];
		}
	}

	long long sol;

	if (n % 2)
	{
		sol = dp[n - 1][2];

		if (dp[n - 2][1] > sol)
		{
			sol = dp[n - 2][1];
		}

		if (n >= 3 && dp[n - 3][0] > sol)
		{
			sol = dp[n - 3][0];
		}
	}

	else
	{
		sol = dp[n - 1][1];

		if (dp[n - 2][0] > sol)
		{
			sol = dp[n - 2][0];
		}
	}

	printf("%lld\n", sol);

	return 0;
}