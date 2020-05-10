#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

#define MOD 1000000007

class Solution {
public:
	int numOfArrays(int n, int m, int k) {
		long long dp[2][101][101] = { 0, };
		for (int j = 1; j <= m; j++) {
			dp[0][0][j] = 0;
			dp[0][1][j] = j;
		}

		for (int i = 1; i < n; i++) {
			for (int l = 0; l <= m; l++) {
				dp[i % 2][0][l] = 0;
			}

			for (int j = 1; j <= k; j++) {
				for (int l = 1; l <= m; l++) {
					dp[i % 2][j][l] = ((dp[!(i % 2)][j][l] - dp[!(i % 2)][j][l - 1] + MOD) % MOD * l) % MOD;

					dp[i % 2][j][l] = (dp[i % 2][j][l] + dp[!(i % 2)][j - 1][l - 1]) % MOD;
				}

				dp[i % 2][j][0] = 0;

				for (int l = 1; l <= m; l++) {
					dp[i % 2][j][l] = (dp[i % 2][j][l] + dp[i % 2][j][l - 1]) % MOD;
				}
			}
		}

		long long sol = 0;
		
		sol = dp[!(n % 2)][k][m];
		
		return (int)sol;
	}
};

int main()
{
	Solution s;

	s.numOfArrays(5, 2, 3);

	return 0;
}