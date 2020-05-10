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
	int constrainedSubsetSum(vector<int>& nums, int k) {
		const int n = nums.size();
		priority_queue<pair<int, int>> pq;
		int lmax;

		lmax = nums[0];

		pq.push({ nums[0],0 });

		for (int i = 1; i < n; i++) {
			while (!pq.empty() && i - pq.top().second > k) {
				pq.pop();
			}

			int base = 0;

			if (!pq.empty()) {

				if (pq.top().first > 0) {
					base = pq.top().first;
				}
			}

			int val;

			val = base + nums[i];

			if (val > lmax) {
				lmax = val;
			}

			pq.push({ val,i });
		}

		return lmax;
	}
};

int main()
{
	Solution s;

	vector<int> arr = { 10,2,-10,5,20 };

	s.constrainedSubsetSum(arr, 2);

	return 0;
}