#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	int i;
	long long dp[100001];
	bool broken[100001] = { 0, };
	int input;

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d", &input);

		broken[input] = true;
	}

	dp[0] = 1;
	dp[1] = !broken[1];

	for (i = 2; i <= n; i++)
	{
		if (broken[i])
		{
			dp[i] = 0;

			continue;
		}

		dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000007;
	}

	printf("%lld\n", dp[n]);

	return 0;
}