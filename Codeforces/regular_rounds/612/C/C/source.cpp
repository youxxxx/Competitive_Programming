#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	bool taken[101] = { 0, };

	vector<int> arr;

	vector<int> select;

	int add = 0;

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		if (input)
		{
			taken[input] = true;

			if (i > 0 && arr[i - 1] && input % 2 != arr[i - 1] % 2)
			{
				add++;
			}
		}

		else
		{
			select.push_back(i);
		}

		arr.push_back(input);
	}

	int	bulb[2] = { 0, };

	for (int i = 1; i <= n; i++)
	{
		if (!taken[i])
		{
			bulb[i % 2]++;
		}
	}

	int dp[101][101][2];

	memset(dp, -1, sizeof(dp));

	dp[0][0][0] = dp[0][0][1] = 0;

	for (int i = 0; i <= bulb[0]; i++)
	{
		for (int j = 0; j <= bulb[1]; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}

			/*
			if (i + j == 1)
			{
				dp[i][j][0] = dp[i][j][1] = 0;

				if (i + j < bulb[0] + bulb[1] && select[i + j - 1] < n - 1 && arr[select[i + j - 1] + 1])
				{
					dp[i][j][0] += arr[select[i + j - 1] + 1] % 2;
					dp[i][j][1] += !(arr[select[i + j - 1] + 1] % 2);
				}
			}
			*/

			if (i > 0)
			{
				int cand = -1;

				if (dp[i - 1][j][0] != -1)
				{
					int val;
					val = dp[i - 1][j][0];

					if (i + j > 1 && select[i + j - 1 - 1] == select[i + j - 1] - 1)
					{

					}

					if (cand == -1 || val < cand)
					{
						cand = val;
					}
				}

				if (dp[i - 1][j][1] != -1)
				{
					int val;
					val = dp[i - 1][j][1];

					if (i + j > 1 && select[i + j - 1 - 1] == select[i + j - 1] - 1)
					{
						val++;
					}

					if (cand == -1 || val < cand)
					{
						cand = val;
					}
				}

				dp[i][j][0] = cand;

				if (dp[i][j][0] != -1 && select[i + j - 1] > 0 && arr[select[i + j - 1] - 1])
				{
					dp[i][j][0] += arr[select[i + j - 1] - 1] % 2;
				}

				if (dp[i][j][0] != -1 && select[i + j - 1] < n - 1 && arr[select[i + j - 1] + 1])
				{
					dp[i][j][0] += arr[select[i + j - 1] + 1] % 2;
				}
			}

			if (j > 0)
			{
				int cand = -1;

				if (dp[i][j - 1][0] != -1)
				{
					int val;
					val = dp[i][j - 1][0];

					if (i + j > 1 &&select[i + j - 1 - 1] == select[i + j - 1] - 1)
					{
						val++;
					}

					if (cand == -1 || val < cand)
					{
						cand = val;
					}	
				}

				if (dp[i][j - 1][1] != -1)
				{
					int val;
					val = dp[i][j - 1][1];

					if (i + j > 1 && select[i + j - 1 - 1] == select[i + j - 1] - 1)
					{
					}

					if (cand == -1 || val < cand)
					{
						cand = val;
					}
				}

				dp[i][j][1] = cand;

				if (dp[i][j][1] != -1 && select[i + j - 1] > 0 && arr[select[i + j - 1] - 1])
				{
					dp[i][j][1] += !(arr[select[i + j - 1] - 1] % 2);
				}

				if (dp[i][j][1] != -1 && select[i + j - 1] < n - 1 && arr[select[i + j - 1] + 1])
				{
					dp[i][j][1] += !(arr[select[i + j - 1] + 1] % 2);
				}
			}
		}
	}

	int sol = -1;

	if (dp[bulb[0]][bulb[1]][0] != -1 && (sol == -1 || dp[bulb[0]][bulb[1]][0] < sol))
	{
		sol = dp[bulb[0]][bulb[1]][0];
	}

	if (dp[bulb[0]][bulb[1]][1] != -1 && (sol == -1 || dp[bulb[0]][bulb[1]][1] < sol))
	{
		sol = dp[bulb[0]][bulb[1]][1];
	}

	printf("%d\n", sol + add);

	return 0;
}