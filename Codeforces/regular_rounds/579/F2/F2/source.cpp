#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

bool func(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second > b.second;
}

bool func2(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first + a.second > b.first + b.second || a.first + a.second == b.first + b.second && a.first > b.first;
}

int main()
{
	int n, r;
	vector<pair<int, int>> pos, neg;
	vector<int> z;
	int dp[2][60001];
	int i, j;
	int input1, input2;
	int negsum = 0;
	bool visited[200] = { 0, };
	int cnt = 0;
	int sol = 0;
	//bool change;

	memset(dp, -1, sizeof(dp));

	scanf("%d %d", &n, &r);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &input1, &input2);

		if (input2 > 0)
		{
			pos.push_back(make_pair(input1, input2));
		}

		else if (input2 < 0)
		{
			neg.push_back(make_pair(input1, input2));

			negsum += input2;
		}

		else
		{
			z.push_back(input1);
		}
	}

	sort(pos.begin(), pos.end());

	sort(neg.begin(), neg.end(), func2);

	for (i = 0; i < pos.size(); i++)
	{
		if (pos[i].first > r)
		{
			break;
		}

		r += pos[i].second;

		cnt++;
	}

	for (i = 0; i < z.size(); i++)
	{
		if (z[i] <= r)
		{
			cnt++;
		}
	}

	//r += negsum;

	dp[1][r] = 0;

	for (i = 0; i < neg.size(); i++)
	{
		for (j = 1; j <= 60000; j++)
		{
			if (dp[!(i % 2)][j] != -1)
			{
				dp[i % 2][j] = dp[!(i % 2)][j];

				if (j + neg[i].second >= 0 && j >= neg[i].first)
				{
					if (dp[i % 2][j + neg[i].second] == -1 || dp[!(i % 2)][j] + 1 > dp[i % 2][j + neg[i].second])
					{
						dp[i % 2][j + neg[i].second] = dp[!(i % 2)][j] + 1;
					}
				}
			}
		}
	}

	for (i = 0; i <= 60000; i++)
	{
		if (dp[!(neg.size() % 2)][i] > sol)
		{
			sol = dp[!(neg.size() % 2)][i];
		}
	}

	sol += cnt;

	printf("%d\n", sol);

	return 0;
}