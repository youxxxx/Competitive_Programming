#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


int main()
{
	long long ub[2] = { 0, };
	long long input;
	long long n;
	long long i, j;
	vector<long long> arr[2];
	long long dp[2][100001];

	scanf("%lld", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr[0].push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr[1].push_back(input);
	}

	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];

	for (i = 1; i < n; i++)
	{
		dp[0][i] = dp[0][i - 1] > dp[1][i - 1] + arr[0][i] ? dp[0][i - 1] : dp[1][i - 1] + arr[0][i];
		dp[1][i] = dp[1][i - 1] > dp[0][i - 1] + arr[1][i] ? dp[1][i - 1] : dp[0][i - 1] + arr[1][i];
	}

	printf("%lld\n", dp[0][n - 1] > dp[1][n - 1] ? dp[0][n - 1]: dp[1][n - 1]);

	return 0;
}