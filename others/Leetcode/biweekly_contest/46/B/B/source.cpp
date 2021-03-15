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
	bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
		const int n = nums.size();
		const int m = groups.size();

		int tot = 0;
		int start = 0;

		for (int i = 0; i < m; i++) {
			int ptr = 0;
			int end = -1;

			if (start + (int)groups[i].size() > n) {
				return false;
			}

			for (int j = start; j + (int)groups[i].size() <= n; j++) {
				bool valid = true;

				for (int k = j; k < j + (int)groups[i].size(); k++) {
					if (groups[i][k - j] != nums[k]) {
						valid = false;

						break;
					}
				}

				if (valid) {
					end = j + (int)groups[i].size();

					break;
				}
			}

			if (end == -1) {
				return false;
			}

			start = end;
		}

		return true;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);
	vector<vector<int>> a = { { 1,-1,-1 },{ 3,-2,0 } };
	vector<int> b = { 1,-1,0,1,-1,-1,3,-2,0 };
	Solution s;
	s.canChoose(a, b);

	return 0;
}