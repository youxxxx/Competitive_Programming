#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

#define MOD 1000000007

using namespace std;

int extendable(long long two, long long three, long long cur, long long n)
{
	long long prod;

	prod = (long long)pow(2.0, two - three)*(1 + three * 2);

	return n / prod - cur < 0 ? 0 : n / prod - cur;
}

int main()
{
	long long dp[2][20][2];
	long long temp, temp2;
	long long prev, prev2;
	long long pw;
	long long n;
	long long i, j;
	long long ub, lb;
	long long dec;

	scanf("%lld", &n);

	if (n == 2)
	{
		printf("1\n");

		return 0;
	}

	if (n == 3)
	{
		printf("4\n");

		return 0;
	}

	pw = (long long)log2(n);

	temp = (long long)pow(2.0, pw - 1);

	dp[0][pw][0] = 1;

	if (temp * 3 <= n)
	{
		dp[0][pw][1] = 1;
	}

	else
	{
		dp[0][pw][1] = 0;
	}

	for (i = 0; i < pw; i++)
	{
		dp[0][i][0] = dp[0][i][1] = 0;
	}

	ub = pw;

	for (i = 1; i < n; i++)
	{
		temp = temp2 = 0;
		prev = prev2 = 0;
		dec = 0;

		if (ub > 0)
		{
			temp = extendable(ub, 1, i, n);

			if (dp[!(i % 2)][ub][1] > 0 && temp > 0)
			{
				dp[i % 2][ub][1] = (dp[!(i % 2)][ub][1] * temp) % MOD;

				temp2 = extendable(ub, 0, i, n);
				dp[i % 2][ub][0] = (dp[!(i % 2)][ub][0] * temp2) % MOD;
			}

			else
			{
				temp2 = extendable(ub, 0, i, n);

				if (temp2 > 0)
				{
					dp[i % 2][ub][1] = 0;
					dp[i % 2][ub][0] = (dp[!(i % 2)][ub][0] * temp2) % MOD;
				}

				else
				{
					dp[i % 2][ub][1] = 0;
					dp[i % 2][ub][0] = 0;

					dec = 1;
				}
			}

			prev = temp2;
			prev2 = temp;
		}

		for (j = ub - 1; j >= 1; j--)
		{
			temp = extendable(j, 0, i, n);
			temp2 = extendable(j, 1, i, n);
			dp[i % 2][j][0] = (dp[!(i % 2)][j + 1][0] % MOD * (temp - prev) % MOD + dp[!(i % 2)][j + 1][1] % MOD * (temp - prev2) % MOD + dp[!(i % 2)][j][0] * temp % MOD) % MOD;
			dp[i % 2][j][1] = ((dp[!(i % 2)][j + 1][1]) * (temp2 - prev2) % MOD + dp[!(i % 2)][j][1] * temp2 % MOD) % MOD;

			prev = temp;
			prev2 = temp2;
		}

		dp[i % 2][0][0] = (((dp[!(i % 2)][1][0]) % MOD * ((n - i) - prev) % MOD + dp[!(i % 2)][1][1] * ((n - i) - prev2) % MOD) % MOD + (dp[!(i % 2)][0][0])*(n - i) % MOD) % MOD;

		if (ub == 0)
		{
			break;
		}

		ub -= dec;
	}

	lb = i;

	for (i = lb; i < n; i++)
	{
		dp[i % 2][0][0] = dp[!(i % 2)][0][0] * (n - i) % MOD;
	}

	printf("%lld\n", dp[!(n % 2)][0][0]);

	return 0;
}