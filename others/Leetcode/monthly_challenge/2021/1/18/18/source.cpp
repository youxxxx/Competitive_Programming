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
	int maxOperations(vector<int>& nums, int k) {
		const int n = nums.size();

		sort(nums.begin(), nums.end());

		int ptr = n - 1;
		int sol = 0;

		for (int i = 0; i < ptr; i++) {
			while (ptr > i&&nums[ptr] + nums[i] > k) {
				ptr--;
			}

			if (ptr > i&&nums[ptr] + nums[i] == k) {
				ptr--;
				sol++;
			}
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}