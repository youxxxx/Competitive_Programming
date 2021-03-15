#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

class Solution {
public:
	vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
		const int n = nums.size();
		vector<int> sol;

		int val = 0;

		for (int i = 1; i < n; i++)	{
			val += nums[i] - nums[0];
		}

		sol.push_back(val);

		for (int i = 1; i < n; i++) {
			int val = sol.back();

			val += (i - 1 - (n - 1 - i))*(nums[i] - nums[i - 1]);

			sol.push_back(val);
		}

		return sol;
	}
};

int main()
{

	return 0;
}