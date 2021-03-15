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
	int minOperations(vector<int>& nums, int x) {
		int lsum[100001];
		int rsum[100001];

		const int n = nums.size();

		lsum[0] = rsum[0] = 0;

		for (int i = 0; i < n; i++) {
			lsum[i + 1] = lsum[i] + nums[i];
			rsum[i + 1] = rsum[i] + nums[n - 1 - i];
		}

		int ptr = n;
		int sol = n + 1;

		for (int i = 0; i <= n; i++) {
			while (ptr > 0 && lsum[i] + rsum[ptr] > x) {
				ptr--;
			}

			if (lsum[i] + rsum[ptr] == x) {
				sol = min(sol, i + ptr);
			}
		}

		if (sol == n + 1) {
			return -1;
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}