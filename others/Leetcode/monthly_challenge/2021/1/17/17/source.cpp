#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

class Solution {
public:
	int countVowelStrings(int n) {
		int dp[2][5];

		for (int j = 0; j < 5; j++) {
			dp[1][j] = 1;
		}

		for (int i = 2; i <= n; i++) {
			int acc = 0;

			for (int j = 0; j < 5; j++) {
				acc += dp[!(i % 2)][j];

				dp[i % 2][j] = acc;
			}
		}

		int sol = 0;

		for (int j = 0; j < 5; j++) {
			sol += dp[n % 2][j];
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}