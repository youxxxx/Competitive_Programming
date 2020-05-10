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

#define MOD 1000000007

using namespace std;

class Solution {
public:
	int numberWays(vector<vector<int>>& hats) {
		const int n = hats.size();
		const int bound = (int)pow(2.0, n);

		int dp[41][1024] = { 0, };

		dp[0][0] = { 1, };

		for (int i = 1; i <= 40; i++) {
			for (int j = 0; j < bound; j++) {
				dp[i][j] = dp[i - 1][j];
			}
			for (int mask = 0; mask < bound; mask++) {

				int bit[10];

				int cnt = 0;

				for (int j = 0; j < n; j++) {
					bit[j] = (mask >> j) % 2;
				}

				for (int j = 0; j < n; j++) {
					if (!bit[j]) {
						bool found = false;

						for (int k = 0; k < hats[j].size(); k++) {
							if (hats[j][k] == i) {
								found = true;

								break;
							} 
						}

						if (found) {
							dp[i][mask | (1 << j)] = (dp[i][mask | (1 << j)] + dp[i - 1][mask]) % MOD;
						}
					}
				}
			}
		}

		return dp[40][bound - 1];
	}
};

int main() {
	vector<vector<int>> hats = { { 3,4 },{ 4,5 },{ 5 } };
	Solution s;

	s.numberWays(hats);

	return 0;
}