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
	int maxAbsoluteSum(vector<int>& nums) {
		const int n = nums.size();
		
		int sol = 0;
		int lmax = 0, lmin = 0;

		for (int i = 0; i < n; i++) {
			lmax += nums[i];
			lmin += nums[i];

			lmax = max(0, lmax);
			lmin = min(0, lmin);

			sol = max(sol, max(lmax, -lmin));
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}