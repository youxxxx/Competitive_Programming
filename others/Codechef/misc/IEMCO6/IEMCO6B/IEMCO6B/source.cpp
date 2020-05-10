#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	int t, z;
	long long input;
	vector<long long> arr;
	int n, i;
	long long dp[2][3], elem[3];
	long long min;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			arr.push_back(input);
		}

		elem[0] = arr[0];
		elem[1] = arr[0];
		elem[2] = arr[0];

		dp[0][0] = dp[0][1] = dp[0][2] = dp[1][0] = dp[1][1] = dp[1][2] = 0;

		for (i = 1; i < n - 1; i++)
		{
			min = dp[!(i % 2)][0] + abs(arr[i] - elem[0]);

			if (dp[!(i % 2)][2] + abs(arr[i] - elem[1]) < min)
			{
				min = dp[!(i % 2)][2] + abs(arr[i] - elem[1]);
			}

			dp[i % 2][0] = min;

			min= dp[!(i % 2)][0] + abs(arr[i + 1] - elem[0]);

			if (dp[!(i % 2)][2] + abs(arr[i + 1] - elem[1]) < min)
			{
				min = dp[!(i % 2)][2] + abs(arr[i + 1] - elem[1]);
			}

			dp[i % 2][1] = min;

			dp[i % 2][2] = dp[!(i % 2)][1] + abs(arr[i] - elem[0]);

			elem[0] = arr[i];

			elem[1] = arr[i - 1];

			elem[2] = arr[i + 1];
		}

		min = dp[!(i % 2)][0] + abs(arr[i] - elem[0]);

		if (dp[!(i % 2)][2] + abs(arr[i] - elem[1]) < min)
		{
			min = dp[!(i % 2)][2] + abs(arr[i] - elem[1]);
		}

		dp[i % 2][0] = min;
		
		dp[i % 2][1] = min;

		dp[i % 2][2] = dp[!(i % 2)][1] + abs(arr[i] - elem[0]);

		min = dp[!(n % 2)][0];

		if (dp[!(n % 2)][2] < min)
		{
			min = dp[!(n % 2)][2];
		}

		printf("%lld\n", min);

		arr.clear();
	}

	return 0;
}