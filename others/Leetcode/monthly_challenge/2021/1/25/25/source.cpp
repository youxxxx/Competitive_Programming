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
	bool kLengthApart(vector<int>& nums, int k) {
		const int n = nums.size();
		int prev = -1;

		for (int i = 0; i < n; i++) {
			if (nums[i]) {
				if (prev != -1) {
					if (i - prev <= k) {
						return false;
					}
				}

				prev = i;
			}
		}

		return true;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}