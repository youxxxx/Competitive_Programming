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
	int maximumScore(vector<int>& nums, int k) {
		const int n = nums.size();

		int l = k;
		int r = k;

		int sol = nums[k];
		int lmin = nums[k];

		while (l > 0 || r < n - 1) {
			if (r == n - 1) {
				lmin = min(lmin, nums[--l]);
			}

			else if (l == 0) {
				lmin = min(lmin, nums[++r]);
			}

			else {
				if (nums[l - 1] > nums[r + 1]) {
					lmin = min(lmin, nums[--l]);
				}

				else {
					lmin = min(lmin, nums[++r]);
				}
			}

			sol = max(sol, lmin*(r - l + 1));
		}

		return sol;
	}
};

int main()
{
}