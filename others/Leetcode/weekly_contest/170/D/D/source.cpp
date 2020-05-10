#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

class Solution {
public:
	int minInsertions(string s) {
		int n;

		n = s.size();

		int dp[501][501];

		dp[0][0] = 0;

		for (int i = 0; i <= n; i++) {
			for (int j = 0; i + j <= n; j++) {
				int cand = -1;

				if (i > 0) {
					if (cand == -1 || dp[i - 1][j] + 1 < cand) {
						cand = dp[i - 1][j] + 1;
					}
				}

				if (j > 0) {
					if (cand == -1 || dp[i][j - 1] + 1 < cand) {
						cand = dp[i][j - 1] + 1;
					}
				}

				if (i > 0 && j > 0) {
					if (cand == -1 || dp[i - 1][j - 1] < cand && s[i - 1] == s[n - j]) {
						cand = dp[i - 1][j - 1];
					}
				}

				if (i > 0 || j > 0)
				{
					dp[i][j] = cand;
				}
			}
		}

		int rvalue = -1;

		for (int i = 0; i < n; i++) {
			if (rvalue == -1 || dp[i][n - 1 - i] < rvalue) {
				rvalue = dp[i][n - 1 - i];
			}
		}

		for (int i = 0; i <= n; i++) {
			if (rvalue == -1 || dp[i][n - i] < rvalue) {
				rvalue = dp[i][n - i];
			}
		}

		return rvalue;
	}
};

int main()
{
	Solution s;

	s.minInsertions("zjveiiwvc");

	return 0;
}