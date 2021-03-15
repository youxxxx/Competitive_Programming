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
	int minAbsDifference(vector<int>& nums, int goal) {
		const int n = nums.size();

		const int ub = (int)pow(2.0, n / 2);

		vector<int> a, b;

		for (int i = 0; i < ub; i++) {
			int temp = i;

			int sum = 0;

			for (int j = 0; j < n / 2; j++) {
				if (temp % 2) {
					sum += nums[j];
				}

				temp /= 2;
			}

			a.push_back(sum);
		}

		const int ub2 = (int)pow(2.0, n - n / 2);

		for (int i = 0; i < ub2; i++) {
			int temp = i;

			int sum = 0;

			for (int j = n / 2; j < n; j++) {
				if (temp % 2) {
					sum += nums[j];
				}

				temp /= 2;
			}

			b.push_back(sum);
		}

		//sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int sol = 1000000000;

		for (int i = 0; i < (int)a.size(); i++) {
			const int target = goal - a[i];

			vector<int>::iterator ret = lower_bound(b.begin(), b.end(), target);
			const int idx = ret - b.begin();

			if (ret != b.end()) {
				sol = min(sol, abs(target - b[idx]));
			}

			if (idx != 0) {
				sol = min(sol, abs(target - b[idx - 1]));
			}
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	Solution s;

	vector<int> arr = { 5,-7,3,5 };
	
	s.minAbsDifference(arr, 6);

	return 0;
}
