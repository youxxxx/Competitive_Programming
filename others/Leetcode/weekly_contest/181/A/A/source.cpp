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
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
		vector<int> sol;
		int n;

		n = nums.size();

		for (int i = 0; i < n; i++) {
			sol.insert(sol.begin() + index[i], nums[i]);
		}
		
		return sol;
	}
};

int main()
{
}