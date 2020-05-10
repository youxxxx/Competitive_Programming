#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& arr) {
		int n, m;

		n = arr.size();

		int dp[2][201];

		for (int i = 0; i < n; i++) {
			dp[0][i] = arr[0][i];
		}

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int lmin = 99999999;
				for (int k = 0; k < n; k++)	{
					if (k == j) {
						continue;
					}

					if (dp[!(i % 2)][k] < lmin) {
						lmin = dp[!(i % 2)][k];
					}
				}

				dp[i % 2][j] = lmin + arr[i][j];
			}
		}

		int lmin = 99999999;

		for (int i = 0; i < n; i++) {
			if (dp[!(n % 2)][i] < lmin)	{
				lmin = dp[!(n % 2)][i];
			}
		}

		return lmin;
	}
};

int main()
{
	return 0;
}