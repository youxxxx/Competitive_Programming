#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<long long> comb[1001];
	vector<long long> arr;
	long long single[1001];
	long long dp[2][600][2];
	long long sum;
	long long psum;
	int t, z;
	int i, j, k, l;
	int lside, rside;
	int n, input;
	int bound;
	int min;

	scanf("%d", &t);

	single[1] = 1;

	for (i = 2; i <= 1000; i++)
	{
		single[i] = (single[i - 1] * 2) % 1000000007;
	}

	comb[0].push_back(1);

	for (i = 1; i <= 1000; i++)
	{
		comb[i].push_back(1);

		/*
		for (j = 1; j < i / 2 + (i % 2); j++)
		{
			comb[i].push_back((comb[i - 1][j - 1] + comb[i - 1][j]) % 1000000007);
		}

		if (!(i % 2))
		{
			comb[i].push_back((comb[i - 1][i / 2 - 1] * 2) % 1000000007);
		}
		*/

		/*
		for (j = 1; j < i; j++)
		{
			comb[i].push_back(((comb[i - 1][j - 1] + comb[i - 1][j])+comb[i][j-1]) % 1000000007);
		}

		comb[i].push_back((comb[i][i - 1] + 1) % 1000000007);
		*/

		for (j = 1; j < i; j++)
		{
			comb[i].push_back(((comb[i - 1][j - 1] + comb[i - 1][j])) % 1000000007);
		}

		comb[i].push_back(1);
	}

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			arr.push_back(input);
		}

		sort(arr.begin(), arr.end());

		sum = single[n];

		dp[0][0][0] = 1;
		dp[0][1][0] = 1;
		dp[0][2][0] = 0;
		dp[0][0][1] = 0;
		dp[0][1][1] = 1;
		dp[0][2][1] = 0;
		
		for (i = 1; i < n; i++)
		{
			min = i;

			if (n - i - 1 < min)
			{
				min = n - i - 1;
			}

			dp[i % 2][0][0] = dp[!(i % 2)][0][0];

			for (j = 1; j <= min + 1; j++)
			{
				dp[i % 2][j][0] = (dp[!(i % 2)][j - 1][0] + dp[!(i % 2)][j][0]) % 1000000007;

				if (i < n - 1 && arr[i] == arr[i + 1])
				{
					dp[i % 2][j][1] = dp[!(i % 2)][j - 1][0] % 1000000007;

					if (arr[i - 1] == arr[i])
					{
						dp[i % 2][j][1] = (dp[i % 2][j][1] + dp[!(i % 2)][j][1]) % 1000000007;
					}
				}

				else
				{
					dp[i % 2][j][1] = 0;
				}

				if (arr[i - 1] == arr[i] && j - 1 <= n - i - 1)
				{
					sum = (sum + dp[!(i % 2)][j][1] * comb[n - i - 1][j - 1]) % 1000000007;
				}
			}

			dp[i % 2][min + 2][0] = dp[i % 2][min + 2][1] = 0;
			/*
			bound = i;

			while (++bound < n&&arr[bound] == arr[i]);

			for (j = i; j < bound - 1; j++)
			{
				for (k = j + 1; k < bound; k++)
				{
					min = j;

					if (n - k - 1 < min)
					{
						min = n - k - 1;
					}

					sum = (sum + comb[j][min] * comb[n - k - 1][min]) % 1000000007;
				}
			}
			
			psum = 0;

			i = bound - 1;			
			*/
			/*
			if (arr[i] == arr[i + 1])
			{
				min = i;

				if (n - i - 2 < min)
				{
					min = n - i - 2;
				}

				for (j = 0; j <= min; j++)
				{
					lside = j;
					rside = j;

					if (j > i / 2)
					{
						lside = j - i;
					}

					if (j > (n - i - 2) / 2)
					{
						rside = (n - i - 2) - j;
					}

					sum = (sum + comb[i][lside] * comb[n - i - 2][rside]) % 1000000007;
				}
			}
			*/

			/*
			if (n - bound < min)
			{
				min = n - bound;
			}

			
			for (j = 0; j <= min; j++)
			{
				lside = j;
				rside = j;

				if (j > i / 2)
				{
					lside = j - i;
				}

				if (j > (n - bound) / 2)
				{
					rside = n - bound - j;
				}

				psum = (psum + comb[i][lside] * comb[n - bound][rside]) % 1000000007;
			}

			sum = (sum + psum*(single[bound - i] - 1)) % 1000000007;

			i = bound - 1;
			*/
		}
		
		printf("%lld\n", sum);

		arr.clear();
	}

	return 0;
}