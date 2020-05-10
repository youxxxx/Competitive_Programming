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

class Solution {
public:
	bool kLengthApart(vector<int>& nums, int k) {
		const int n = nums.size();
		int last = -1;

		for (int i = 0; i < n; i++) {
			if (nums[i]) {
				if (last == -1) {
					last = i;
				}

				else {
					if (i - last <= k) {
						return false;
					}

					last = i;
				}
			}
		}

		return true;
	}
};

int main() {

	return 0;
}