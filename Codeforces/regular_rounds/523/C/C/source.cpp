#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n;
	int i, j;
	vector<long long> arr;
	long long input;
	vector<long long> dp[2];
	long long sol = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);
	}

	dp[0].push_back(1);
	dp[0].push_back(1);

	for (i = 1; i < n; i++)
	{
		dp[i % 2].push_back(1);

		for (j = 1; j <= i; j++)
		{
			dp[i % 2].push_back((dp[!(i % 2)][j] + dp[!(i % 2)][j - 1] * !(arr[i] % j)) % 1000000007);
		}

		dp[i % 2].push_back((dp[!(i % 2)][i] * !(arr[i] % (i + 1))) % 1000000007);

		dp[!(i % 2)].clear();
	}

	for (i = 1; i <= n; i++)
	{
		sol = (sol + dp[!(n % 2)][i]) % 1000000007;
	}

	printf("%I64d", sol);

	return 0;
}