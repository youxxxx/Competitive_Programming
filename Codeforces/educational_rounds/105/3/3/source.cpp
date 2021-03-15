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
	int missingNumber(vector<int>& nums) {
		const int n = nums.size();
		int sol = n*(n + 1) / 2;

		for (int i = 0; i < n; i++) {
			sol -= nums[i];
		}

		return sol;
	}
};

int main()
{

}