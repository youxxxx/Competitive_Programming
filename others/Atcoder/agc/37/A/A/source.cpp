#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	char input[200001];
	string str;
	int i, n;
	int dp[200000][2];

	scanf("%s", input);

	str = input;

	n = str.size();

	dp[0][0] = 1;
	dp[0][1] = 1;

	for (i = 1; i < n; i++)
	{
		dp[i][0] = dp[i - 1][1];

		if (str[i - 1] != str[i] && dp[i - 1][0] + 1 > dp[i][0])
		{
			dp[i][0] = dp[i - 1][0] + 1;
		}

		if (i > 1 && dp[i - 2][1] + 1 > dp[i][0])
		{
			dp[i][0] = dp[i - 2][1] + 1;
		}

		dp[i][1] = dp[i - 1][0] + 1;
	}

	printf("%d\n", dp[n - 1][0]);

	return 0;
}