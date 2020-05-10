#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	char input[1000002];
	string str;

	//freopen("input.txt", "r", stdin);

	scanf("%s", input);
	str = input;

	int n;
	n = str.size();

	int dp[2][2];

	dp[0][0] = str[0] - '0';
	dp[0][1] = 10 - (str[0] - '0');

	for (int i = 1; i < n; i++)
	{
		dp[i % 2][0] = (dp[!(i % 2)][0] < dp[!(i % 2)][1] ? dp[!(i % 2)][0] : dp[!(i % 2)][1]) + (str[i] - '0');
		dp[i % 2][1] = (dp[!(i % 2)][0] + 1 < dp[!(i % 2)][1] - 1 ? dp[!(i % 2)][0] + 1 : dp[!(i % 2)][1] - 1) + (10 - (str[i] - '0'));
	}

	printf("%d\n", dp[!(n % 2)][0] < dp[!(n % 2)][1] ? dp[!(n % 2)][0] : dp[!(n % 2)][1]);

	return 0;
}