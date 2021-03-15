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
	int specialArray(vector<int>& nums) {
		const int n = nums.size();

		for (int i = 0; i <= n; i++) {
			int cnt = 0;

			for (int j = 0; j < n; j++) {
				if (i <= nums[j]) {
					cnt++;
				}
			}

			if (i == cnt) {
				return i;
			}
		}

		return -1;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}