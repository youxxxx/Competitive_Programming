#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n, k, x;
	vector<long long> arr;
	long long input;
	long long **dp;
	long long max=0, lmax;
	int i, j, l;

	scanf("%d %d %d", &n, &k, &x);

	dp = new long long*[n];

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);

		dp[i] = new long long[i + 2];
	}

	if (x < n / k)
	{
		printf("-1");

		return 0;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i + 1; j++)
		{
			dp[i][j] = -1;
		}
	}

	for (i = 0; i < k - 1; i++)
	{
		dp[i][0] = 0;
	}

	dp[0][1] = arr[0];

	for (i = 1; i < n; i++)
	{
		for (j = i / k + 1; j <= i + 1 && j <= x; j++)
		{
			lmax = 0;

			for (l = 1; l <= k; l++)
			{
				if (i - l < 0 || i - l + 1 < j - 1 || (i - l) / k > j - 1)
				{
					break;
				}

				if (dp[i - l][j - 1] != -1 && dp[i - l][j - 1] + arr[i] > lmax)
				{
					lmax = dp[i - l][j - 1] + arr[i];
				}
			}

			dp[i][j] = lmax;
		}
	}

	for (i = x - 1; i < n; i++)
	{
		if (dp[i][x] > max)
		{
			max = dp[i][x];
		}
	}

	printf("%I64d", max);

	return 0;
}