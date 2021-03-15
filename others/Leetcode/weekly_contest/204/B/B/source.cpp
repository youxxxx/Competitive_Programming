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

using namespace std;

class Solution {
public:
	int getMaxLen(vector<int>& nums) {
		const int n = nums.size();

		int sol = 0;

		int lb = -1;
		int nlb = -1;
		int nub;
		int sign;

		for (int i = 0; i < n; i++) {
			if (nums[i] == 0) {
				lb = -1;
				nlb = -1;

				continue;
			}

			if (lb == -1) {
				lb = i;
				sign = 1;
			}

			if (nums[i] < 0) {
				if (nlb == -1) {
					nlb = i;
				}

				nub = i;

				sign *= -1;
			}

			if (sign == 1) {
				if (i - lb + 1 > sol) {
					sol = i - lb + 1;
				}
			}

			else {
				const int lmin = nlb - lb + 1 < i - nub + 1 ? nlb - lb + 1 : i - nub + 1;

				if (i - lb + 1 - lmin > sol) {
					sol = i - lb + 1 - lmin;
				}
			}
		}

		return sol;
	}
};

int main()
{
	Solution s;

	return 0;
}