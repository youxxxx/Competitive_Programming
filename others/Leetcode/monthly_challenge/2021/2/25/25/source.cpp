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
	int findUnsortedSubarray(vector<int>& nums) {
		const int n = nums.size();
		int lmax = -100001;
		int idx = -1;
		int left = n;
		int right = n - 1;

		stack<pair<int, int>> s;

		for (int i = 0; i < n; i++) {
			while (!s.empty() && s.top().first > nums[i]) {
				left = min(left, s.top().second);

				s.pop();
			}

			if (nums[i] > lmax) {
				lmax = nums[i];
			}

			else if (nums[i] < lmax) {
				right = i;
			}

			s.push({ nums[i],i });
		}

		return right - left + 1;
	}
};