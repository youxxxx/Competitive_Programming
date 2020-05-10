#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	long long sum;
	long long comb;
	long long p;
	vector<long long> *dp;
	long long input;
	vector<long long> arr;
	int k, n, pre = 0, prek = 0;
	int i, j;
	int ptr;

	dp = new vector<long long>[100001];

	/*
	dp = new long long*[100001];

	for (i = 1; i <= 100000; i++)
	{
		dp[i] = new long long[i + 2];
	}

	dp[0][0] = 1;
	dp[0][1] = 1;
	*/

	dp[0].push_back(1);
	dp[0].push_back(1);

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		sum = 0;

		scanf("%d %lld %d", &n, &p, &k);

		if (n > pre)
		{
			/*
			for (i = 1; i < n; i++)
			{
				//dp[i][0] = 1;

				dp[i].push_back(1);

				for (j = 1; j <= i + 1 && j <= k - 2; j++)
				{
					//dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007;

					dp[i].push_back((dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007);
				}
			}

			for (j = 1; j <= i + 1&&j <= k - 2; j++)
			{
				//dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007;

				dp[i].push_back((dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007);
			}
			*/

			if (k > prek)
			{
				for (i = 1; i < pre; i++)
				{
					//dp[i][0] = 1;

					dp[i].push_back(1);

					for (j = prek - 1; j <= i + 1 && j <= k - 2; j++)
					{
						//dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007;

						dp[i].push_back((dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007);
					}
				}
			}

			for (i = pre; i < n; i++)
			{
				dp[i].push_back(1);

				for (j = 1; j <= i + 1 && (j <= k - 2 || j <= prek - 2); j++)
				{
					//dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007;

					dp[i].push_back((dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007);
				}
			}
		}

		else
		{
			if (k > prek)
			{
				for (i = 1; i < n; i++)
				{
					//dp[i][0] = 1;

					dp[i].push_back(1);

					for (j = prek - 1; j <= i + 1 && j <= k - 2; j++)
					{
						//dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007;

						dp[i].push_back((dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007);
					}
				}
			}

			for (i = n; i < pre; i++)
			{
				dp[i].push_back(1);

				for (j = 1; j <= i + 1 && (j <= k - 2 || j <= prek - 2); j++)
				{
					//dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007;

					dp[i].push_back((dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007);
				}
			}
		}

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			arr.push_back(input);
		}

		if (k == 1)
		{
			printf("%d\n", n);

			continue;
		}

		ptr = k - 1;

		for (i = 0; i < n - k + 1; i++)
		{
			for (j = k - 2; j < ptr - 1 - i; j++)
			{
				sum = (sum + dp[j][k - 2]) % 1000000007;
			}

			while (ptr < n && (arr[ptr] + arr[i] - 1) / arr[i] <= p)
			{
				if (ptr - i >= k - 1)
				{
					sum = (sum + dp[ptr - i - 1][k - 2]) % 1000000007;
				}

				ptr++;
			}

			ptr--;

			if (ptr - i < k - 1)
			{
				continue;
			}
		}

		printf("%lld\n", sum);

		arr.clear();

		if (n > pre)
		{
			pre = n;
		}

		if (k > prek)
		{
			prek = k;
		}
	}

	return 0;
}