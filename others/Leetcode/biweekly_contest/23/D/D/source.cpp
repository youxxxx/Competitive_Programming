#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

class Solution {
public:
	int maxSatisfaction(vector<int>& satisfaction) {
		int dp[2][501];
		int lmax = 0;
		const int n = satisfaction.size();

		dp[1][0] = 0;

		sort(satisfaction.begin(), satisfaction.end());

		for (int i = 0; i < n; i++) {
			dp[i % 2][0] = 0;

			for (int j = 1; j <= i; j++) {
				dp[i%2][j] = dp[!(i % 2)][j] > dp[!(i % 2)][j - 1] + satisfaction[i] * j ? dp[!(i % 2)][j] : dp[!(i % 2)][j - 1] + satisfaction[i] * j;
			}

			dp[i % 2][i + 1] = dp[!(i % 2)][i] + satisfaction[i] * (i + 1);
		}

		for (int i = 1; i <= n; i++) {
			if (dp[!(n % 2)][i] > lmax) {
				lmax = dp[!(n % 2)][i];
			}
		}

		return lmax;
	}
};

int main()
{
	Solution s;

	return 0;
}