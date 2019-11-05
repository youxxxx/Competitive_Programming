#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

#define MOD 1000000007

using namespace std;

int main()
{
	char input[100001];
	string str;
	int n;
	int i, j, k;
	long long dp[2][13] = { 0, };
	long long pos[2][13] = { 0, };
	int ptr;

	scanf("%s", input);

	str = input;

	n = str.size();

	for (i = 0; i < 13; i++)
	{
		pos[0][i] = i % 13;
	}

	if (str[n - 1] == '?')
	{
		for (i = 0; i < 10; i++)
		{
			dp[0][i] = 1;
		}
	}

	else
	{
		dp[0][str[n - 1] - '0'] = 1;
	}

	for (i = 1; i < n; i++)
	{
		ptr = n - i - 1;

		for (j = 0; j < 13; j++)
		{
			pos[i % 2][j] = pos[!(i % 2)][(j * 10) % 13];
		}

		if (str[ptr] == '?')
		{
			for (j = 0; j < 13; j++)
			{
				dp[i % 2][j] = 0;
			}

			for (k = 0; k < 10; k++)
			{
				for (j = 0; j < 13; j++)
				{
					dp[i % 2][(j + pos[i % 2][k]) % 13] = (dp[i % 2][(j + pos[i % 2][k]) % 13] + dp[!(i % 2)][j]) % MOD;
				}
			}
		}

		else
		{
			for (j = 0; j < 13; j++)
			{
				dp[i % 2][j] = 0;
			}

			for (j = 0; j < 13; j++)
			{
				dp[i % 2][(j + pos[i % 2][str[ptr] - '0']) % 13] = dp[!(i % 2)][j];
			}
		}
	}

	printf("%lld\n", dp[!(n % 2)][5]);

	return 0;
}
