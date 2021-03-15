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
	int minMoves(vector<int>& nums, int k) {

		vector<int> ones;

		for (int i = 0; i < (int)nums.size(); i++) {
			if (nums[i]) {
				ones.push_back(i);
			}
		}
		const int n = ones.size();

		long long sol;
		long long cur = 0;
		long long leftmost = ones[(k - 1) / 2] - ones[0];

		for (int i = 0; i < k; i++) {
			cur += abs(ones[(k - 1) / 2] - ones[i]);
		}

		sol = cur;

		for (int i = 1; i <= n - k; i++) {
			const long long dist = ones[(k - 1) / 2 + i] - ones[(k - 1) / 2 + i - 1];
			leftmost += dist;
			cur += (k - k / 2)* (dist) - k / 2 * (dist);
			cur -= leftmost;
			cur += ones[i + k - 1] - ones[(k - 1) / 2 + i];

			leftmost = ones[(k - 1) / 2 + i] - ones[i];

			sol = min(sol, cur);
		}

		long long subt = 0;

		if (k % 2) {
			subt = (k / 2) * (k / 2 + 1);
		}

		else {
			subt = (k / 2)*(k / 2 + 1) / 2 + (k / 2 - 1)*(k / 2) / 2;
		}

		return (int)sol - subt;
	}
};

int main()
{
	vector<int> arr = { 1,0,0,1,0,1,1,1,0,1,1 };

	Solution s;

	s.minMoves(arr, 7);
	//freopen("input.txt", "r", stdin);

	return 0;
}