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
	vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
		vector<vector<int>> ord(200003);
		const int n = nums.size();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < nums[i].size(); j++) {
				ord[i + j].push_back(nums[i][j]);
			}
		}

		vector<int> sol;


		for (int i = 0; i <= 200000; i++) {
			for (int j = ord[i].size() - 1; j >= 0; j--) {
				sol.push_back(ord[i][j]);
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