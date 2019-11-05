#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n, l, r;
	long long dp[2][3];
	long long num[3];
	long long i;

	scanf("%I64d %I64d %I64d", &n, &l, &r);

	if (r - l < 3)
	{
		for (i = 0; i < 3; i++)
		{
			num[i] = 0;
		}

		for (i = l; i <= r; i++)
		{
			num[i % 3]++;
		}
	}

	else
	{
		l--;

		for (i = 0; i < 3; i++)
		{
			num[i] = r / 3 - l / 3;
		}

		if (l % 3 == 1)
		{
			num[1]--;
		}

		else if (l % 3 == 2)
		{
			num[1]--;
			num[2]--;
		}

		if (r % 3 == 1)
		{
			num[1]++;
		}

		else if (r % 3 == 2)
		{
			num[1]++;
			num[2]++;
		}
	}

	for (i = 0; i < 3; i++)
	{
		dp[0][i] = num[i];
	}

	for (i = 1; i < n; i++)
	{
		dp[i % 2][0] = (dp[!(i % 2)][0] * num[0]) % 1000000007;
		dp[i % 2][0] = (dp[i % 2][0] + (dp[!(i % 2)][1] * num[2])) % 1000000007;
		dp[i % 2][0] = (dp[i % 2][0] + (dp[!(i % 2)][2] * num[1])) % 1000000007;

		dp[i % 2][1] = (dp[!(i % 2)][1] * num[0]) % 1000000007;
		dp[i % 2][1] = (dp[i % 2][1] + (dp[!(i % 2)][0] * num[1])) % 1000000007;
		dp[i % 2][1] = (dp[i % 2][1] + (dp[!(i % 2)][2] * num[2])) % 1000000007;

		dp[i % 2][2] = (dp[!(i % 2)][2] * num[0]) % 1000000007;
		dp[i % 2][2] = (dp[i % 2][2] + (dp[!(i % 2)][1] * num[1])) % 1000000007;
		dp[i % 2][2] = (dp[i % 2][2] + (dp[!(i % 2)][0] * num[2])) % 1000000007;
	}

	printf("%I64d\n", dp[!(n % 2)][0]);

	return 0;
}