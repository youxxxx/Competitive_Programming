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
	int findLHS(vector<int>& nums) {
		const int n = nums.size();
		int prev = -1000000002;
		int pcnt = 0;
		int cnt = 0;
		int sol = 0;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < n; i++) {
			if (nums[i] == prev) {
				cnt++;

				if (pcnt) {
					sol = max(sol, cnt + pcnt);
				}
			}

			else {
				if (nums[i] == prev + 1) {
					pcnt = cnt;
				}

				else {
					pcnt = 0;
				}

				prev = nums[i];
				cnt = 1;

				if (pcnt) {
					sol = max(sol, cnt + pcnt);
				}
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