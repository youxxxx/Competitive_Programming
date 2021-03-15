#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

class Solution {
public:
	int minDistance(vector<int>& houses, int k) {
		const int n = houses.size();

		if (n == k) {
			return 0;
		}

		sort(houses.begin(), houses.end());

		int dp[101][101];

		memset(dp, -1, sizeof(dp));

		dp[0][0] = 0;
		dp[0][1] = 0;

		int cost[101][101];

		for (int i = 0; i < n; i++) {
			cost[i][i] = 0;

			for (int j = 1; i - j + 1 >= 0 && i + j - 1 < n; j++) {
				const int prev = cost[i - j + 1][i + j - 1];

				if (i - j >= 0) {
					cost[i - j][i + j - 1] = prev + abs(houses[i] - houses[i - j]);
				}

				if (i + j < n) {
					cost[i - j + 1][i + j] = prev + abs(houses[i] - houses[i + j]);
				}

				if (i - j >= 0 && i + j < n) {
					cost[i - j][i + j] = prev + abs(houses[i] - houses[i - j]) + abs(houses[i] - houses[i + j]);
				}
			}
		}

		for (int i = 1; i < n; i++) {
			dp[i][0] = 0;
			dp[i][1] = cost[0][i];

			for (int j = 2; j <= i + 1; j++) {
				for (int l = 0; l < i; l++) {
					if (dp[i][j] == -1 || dp[l][j - 1] + cost[l + 1][i] < dp[i][j]) {
						dp[i][j] = dp[l][j - 1] + cost[l + 1][i];
					}
				}
			}
		}

		return dp[n - 1][k];
	}
};

int main()
{
	vector<int> arr = { 1,8,12,10,3 };
	Solution s;

	s.minDistance(arr, 3);

	return 0;
}