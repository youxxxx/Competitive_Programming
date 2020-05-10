#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
	int minDifficulty(vector<int>& jobDifficulty, int d) {
		int n;

		n = jobDifficulty.size();

		if (n < d) {
			return -1;
		}

		int dp[301][301];
		int lmax[301][301];

		memset(dp, -1, sizeof(dp));

		for (int i = 0; i < n; i++) {
			int curmax = -1;

			for (int j = i; j < n; j++) {
				if (jobDifficulty[j] > curmax) {
					curmax = jobDifficulty[j];
				}

				lmax[i][j] = curmax;
			}
		}

		for (int i = 0; i < n; i++) {
			dp[0][i] = lmax[0][i];
		}

		for (int i = 1; i < d; i++) {
			for (int j = i; j < n; j++) {
				for (int k = i; k <= j; k++) {
					if (dp[i][j] == -1 || dp[i - 1][k - 1] + lmax[k][j] < dp[i][j]) {
						dp[i][j] = dp[i - 1][k - 1] + lmax[k][j];
					}
				}
			}
		}

		return dp[d - 1][n - 1];
	}
};

int main()
{
	Solution s;
	vector<int> arr = {7,1,7,1,7,1};

	s.minDifficulty(arr, 3);

	return 0;
}