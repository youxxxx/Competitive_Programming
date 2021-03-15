#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

#define MOD 1000000007

using namespace std;

class Solution {
public:
	int numOfSubarrays(vector<int>& arr) {
		int dp[2][2] = { 0, };
		const int n = arr.size();

		int sol = 0;

		for (int i = 0; i < n; i++) {
			const int parity = arr[i] % 2;
			dp[i % 2][0] = dp[!(i % 2)][parity];
			dp[i % 2][1] = dp[!(i % 2)][(parity + 1) % 2];

			dp[i % 2][0] %= MOD;
			dp[i % 2][1] %= MOD;

			dp[i % 2][parity]++;
			dp[i % 2][parity] %= MOD;

			sol = (sol + dp[i % 2][1]) % MOD;
		}

		return sol;
	}
};

int main()
{

	return 0;
}