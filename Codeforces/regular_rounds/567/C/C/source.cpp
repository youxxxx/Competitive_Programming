#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

#define MOD 1000000007

using namespace std;

int main()
{
	int n, m;
	char input[2000];
	string str;
	vector<string> arr;
	int i, j, k;
	long long sol = 0;
	long long dp[1000][1000], v[1000][1000], h[1000][1000], size[1000][1000];
	bool found = false;

	scanf("%d %d", &n, &m);

	if (n < 3)
	{
		printf("0\n");

		return 0;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		str = input;

		arr.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		h[i][0] = 1;

		for (j = 1; j < m; j++)
		{
			if (arr[i][j - 1] == arr[i][j])
			{
				h[i][j] = h[i][j - 1] + 1;
			}

			else
			{
				h[i][j] = 1;
			}
		}
	}

	for (i = 0; i < m; i++)
	{
		v[0][i] = 1;

		for (j = 1; j < n; j++)
		{
			if (arr[j - 1][i] == arr[j][i])
			{
				v[j][i] = v[j - 1][i] + 1;
			}

			else
			{
				v[j][i] = 1;
			}
		}
	}

	for (i = 2; i < n; i++)
	{
		found = false;

		for (k = 1; i - k * 3 + 1 >= 0; k++)
		{
			if (arr[i][0] != arr[i - k][0] && arr[i - k][0] != arr[i - 2 * k][0] && v[i][0] >= k&&v[i - k][0] >= k&&v[i - 2 * k][0] >= k)
			{
				dp[i][0] = 1;

				size[i][0] = k;

				found = true;

				sol += dp[i][0];

				break;
			}
		}

		if (!found)
		{
			dp[i][0] = 0;
			size[i][0] = 0;
		}

		for (j = 1; j < m; j++)
		{
			found = false;
			
			if (size[i][j - 1] != 0)
			{
				k = size[i][j - 1];

				if (arr[i][j] != arr[i - k][j] && arr[i - k][j] != arr[i - 2 * k][j] && v[i][j] == k&&v[i - k][j] == k&&v[i - 2 * k][j] >= k && h[i][j] >= 2 && h[i - k][j] >= 2 && h[i - 2 * k][j] >= 2)
				{
					dp[i][j] = dp[i][j - 1] + 1;

					size[i][j] = k;

					found = true;

					sol += dp[i][j];

					continue;
				}
			}

			for (k = 1; i - k * 3 + 1 >= 0; k++)
			{
				if (arr[i][j] != arr[i - k][j] && arr[i - k][j] != arr[i - 2 * k][j] && v[i][j] == k&&v[i - k][j] == k&&v[i - 2 * k][j] >= k)
				{
					dp[i][j] = 1;

					size[i][j] = k;

					found = true;

					sol += dp[i][j];

					break;
				}
			}

			if (!found)
			{
				dp[i][j] = 0;
				size[i][j] = 0;
			}
		}
	}

	printf("%lld\n", sol);

	return 0;
}