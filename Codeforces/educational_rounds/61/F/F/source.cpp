#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	char pre;
	int n;
	int i, j, k;
	int ptr = 0;
	char input;
	vector<int> color;
	int cnt = 0;
	bool found;
	char dummy;
	int dp[501][501];


	scanf("%d %c", &n, &pre);

	for (i = 1; i < n; i++)
	{
		scanf("%c", &input);

		if (input != pre)
		{
			color.push_back(pre - 'a');

			pre = input;
		}
	}

	color.push_back(pre - 'a');

	if (color.size() == 1)
	{
		printf("1\n");

		return 0;
	}

	for (i = 0; i < color.size(); i++)
	{
		dp[i][i] = 0;
	}

	for (int i = 1; i < color.size(); i++)
	{
		for (j = 0; j + i < color.size(); j++)
		{
			dp[j][j + i] = 400;

			for (k = j; k < j + i; k++)
			{
				if (dp[j][k] + dp[k + 1][j + i] + (color[j] != color[k + 1]) < dp[j][j + i])
				{
					dp[j][j + i] = dp[j][k] + dp[k + 1][j + i] + (color[j] != color[k + 1]);
				}
			}
		}
	}

	printf("%d\n", dp[0][color.size()-1] + 1);

	return 0;
}