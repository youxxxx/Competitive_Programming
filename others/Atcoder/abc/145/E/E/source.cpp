#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>

#define MOD 1000000007

using namespace std;

int main()
{
	int n;
	int t;
	int dp[2][3001];
	vector<pair<int,int>> arr;
	int lmax = 0;
	int time, cand;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &t);

	for (int i = 0; i < n; i++)
	{
		int input1, input2;

		scanf("%d %d", &input1, &input2);

		arr.push_back(make_pair(input1, input2));
	}

	sort(arr.begin(), arr.end());

	for (int i = 1; i <= t; i++)
	{
		dp[1][i] = -1;
	}

	dp[1][0] = 0;

	for (int i = 0; i < n; i++)
	{
		dp[i % 2][0] = 0;

		for (int j = 1; j <= t; j++)
		{
			dp[i % 2][j] = dp[!(i % 2)][j];
		}

		for (int j = 0; j < t; j++)
		{
			if (dp[!(i % 2)][j] != -1)
			{
				time = j + arr[i].first;
				cand = dp[!(i % 2)][j] + arr[i].second;

				if (cand > lmax)
				{
					lmax = cand;
				}

				if (time < t && (cand > dp[i % 2][time]))
				{
					dp[i % 2][time] = cand;
				}
			}
		}
	}

	printf("%d\n", lmax);

	return 0;
}