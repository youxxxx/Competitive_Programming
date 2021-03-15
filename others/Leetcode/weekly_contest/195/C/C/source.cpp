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

#define MOD 1000000007

using namespace std;

long long exp(int base, int pw) {
	long long temp = base;
	long long ret = 1;

	while (pw) {
		if (pw % 2) {
			ret = ret*temp%MOD;
		}

		temp = temp*temp%MOD;
		pw /= 2;
	}

	return ret;
}

class Solution {
public:
	int numSubseq(vector<int>& nums, int target) {
		const int n = nums.size();

		sort(nums.begin(), nums.end());

		int ptr = 0;

		while (ptr < n&&nums[0] + nums[ptr] <= target) {
			ptr++;
		}

		long long sol = 0;

		for (int i = 0; i < n; i++) {
			if (ptr < i) {
				break;
			}

			while (ptr > i&&nums[i] + nums[ptr - 1] > target) {
				ptr--;
			}

			if (ptr - i) {
				sol = (sol + exp((long long)2, (long long)(ptr - i - 1))) % MOD;
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