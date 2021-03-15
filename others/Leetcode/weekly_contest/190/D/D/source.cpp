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
	int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
		const int n = nums1.size();
		const int m = nums2.size();
		int dp[501][501];

		for (int i = 0; i <= (n > m ? n : m); i++)
		{
			for (int j = 0; j <= (n > m ? n : m); j++)
			{
				dp[i][j] = -2000000000;
			}
		}
		int sol = -2000000000;

		for (int i = 1; i <= n; i++)
		{
			dp[i][0] = 0;

			int lmax = 0;

			for (int j = 1; j <= m; j++)
			{
				if (dp[i - 1][j - 1] > lmax)
				{
					lmax = dp[i - 1][j - 1];
				}

				dp[i][j] = lmax + nums1[i - 1] * nums2[j - 1];

				if (dp[i - 1][j] > dp[i][j])
				{
					dp[i][j] = dp[i - 1][j];
				}

				if (dp[i][j] > sol)
				{
					sol = dp[i][j];
				}
			}
		}

		return sol;
	}
};

using namespace std;

int main()
{
	Solution s;
	vector<int> arr = { -1, -1 }, arr2 = {1, 1};

	s.maxDotProduct(arr, arr2);

	return 0;
}