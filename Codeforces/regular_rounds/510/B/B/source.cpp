#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool func(pair<int, int> &a, pair<int, int> &b)
{
	return a.first < b.first || a.first == b.first&&a.second > b.second;
}

int main()
{
	int n;
	int input1, i, j, temp;
	char input2[5];
	string str;
	vector<pair<int,int>> price;
	int dp[2][8] = { 0, };
	int cand;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input1);

		scanf("%s", input2);

		str = input2;

		temp = 0;

		for (j = 0; j < str.size(); j++)
		{
			switch (str[j])
			{
			case 'A':
				temp += 4;
				break;
			case 'B':
				temp += 2;
				break;
			default:
				temp++;
				break;
			}
		}

		price.push_back(pair<int, int>(input1, temp));
	}

	sort(price.begin(), price.end(), func);

	dp[0][price[0].second] = price[0].first;

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < 8; j++)
		{
			dp[i % 2][j] = dp[!(i % 2)][j];
		}

		if (dp[!(i % 2)][price[i].second] == 0)
		{
			dp[i % 2][price[i].second] = dp[!(i % 2)][price[i].second] + price[i].first;
		}

		for (j = 0; j < 8; j++)
		{
  			if (dp[!(i % 2)][j] != 0 && (dp[i % 2][j | price[i].second] == 0 ||dp[!(i % 2)][j] + price[i].first < dp[i % 2][j | price[i].second]))
			{
				dp[i % 2][j | price[i].second] = dp[!(i % 2)][j] + price[i].first;
			}
		}
	}

	if (dp[!(n % 2)][7] == 0)
	{
		printf("-1");
	}

	else
	{
		printf("%d", dp[!(n % 2)][7]);
	}

	return 0;
}