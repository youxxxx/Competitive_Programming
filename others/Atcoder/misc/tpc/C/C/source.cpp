#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int i;
	int index;
	long long sum = 0;
	vector<long long> arr;
	long long input;
	long long dp[2][2];
	long long max;
	int mid1, mid2;
	int pre1, pre2;
	int cur1, cur2;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	if (n % 2)
	{
		mid1 = mid2 = n / 2;

		dp[0][0] = dp[0][1] = 0;
	}

	else
	{
		mid1 = n / 2 - 1;
		mid2 = n / 2;

		dp[0][0] = dp[0][1] = arr[mid2] - arr[mid1];
	}

	pre1 = mid1;
	pre2 = mid2;

	for (i = 1; i <= (n - 1) / 2; i++)
	{
		if (i % 2)
		{
			cur1 = i / 2;
			cur2 = n - i / 2 - 1;
		}

		else
		{
			cur1 = mid1 - i / 2;
			cur2 = mid2 + i / 2;
		}

		max = dp[!(i % 2)][0] + abs(arr[pre1] - arr[cur2]);

		if (dp[!(i % 2)][1] + abs(arr[pre2] - arr[cur2])>max)
		{
			max = dp[!(i % 2)][1] + abs(arr[pre2] - arr[cur2]);
		}

		dp[i % 2][0] = max + abs(arr[cur2] - arr[cur1]);

		max = dp[!(i % 2)][0] + abs(arr[pre1] - arr[cur1]);

		if (dp[!(i % 2)][1] + abs(arr[pre2] - arr[cur1])>max)
		{
			max = dp[!(i % 2)][1] + abs(arr[pre2] - arr[cur1]);
		}

		dp[i % 2][1] = max + abs(arr[cur2] - arr[cur1]);

		pre1 = cur1;
		pre2 = cur2;
	}

	max = dp[!(i % 2)][0];

	if (dp[!(i % 2)][1] > max)
	{
		max = dp[!(i % 2)][1];
	}

	printf("%lld\n", max);
	
	return 0;
}