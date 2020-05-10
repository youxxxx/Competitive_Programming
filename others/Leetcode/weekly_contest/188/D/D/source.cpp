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
	int acc[51][51];

	int cut(int lx, int ly, int ux, int uy) {
		return !!(acc[ux][uy] - acc[ux][ly] - acc[lx][uy] + acc[lx][ly]);
	}

	int ways(vector<string>& pizza, int k) {
		const int n = pizza.size();
		const int m = pizza[0].size();

		for (int j = 0; j <= m; j++) {
			acc[0][j] = 0;
		}

		for (int i = 1; i <= n; i++) {
			int racc = 0;

			acc[i][0] = 0;

			for (int j = 1; j <= m; j++) {
				racc += (pizza[i - 1][j - 1] == 'A');

				acc[i][j] = racc + acc[i - 1][j];
			}
		}

		int dp[11][51][51] = { 0, };

		dp[0][0][0] = 1;

		for (int i = 1; i <= k; i++) {
			for (int j = 0; j <= n; j++) {
				for (int l = 0; l <= m; l++) {
					for (int z = 0; z < j; z++) {
						dp[i][j][l] = (dp[i][j][l] + cut(z, l, j, m) * dp[i - 1][z][l]) % MOD;
					}

					for (int z = 0; z < l; z++) {
						dp[i][j][l] = (dp[i][j][l] + cut(j, z, n, l) * dp[i - 1][j][z]) % MOD;
					}
				}
			}
		}

		int sol = 0;

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				int valid = cut(i, j, n, m);

				sol = (sol + dp[k - 1][i][j] * valid) % MOD;
			}
		}

		return sol;
	}
};

int main()
{
	vector<string> arr = { "A..","A..","..." };
	Solution s;

	s.ways(arr, 3);

	return 0;
}