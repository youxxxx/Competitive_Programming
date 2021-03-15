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
	vector<int> findErrorNums(vector<int>& nums) {
		const int n = nums.size();
		vector<int> cnt(n + 1);

		for (int i = 0; i < n; i++) {
			cnt[nums[i]]++;
		}

		vector<int> sol(2);

		for (int i = 1; i <= n; i++) {
			if (cnt[i] == 2) {
				sol[0] = i;
			}

			else if (!cnt[i]) {
				sol[1] = i;
			}
		}

		return sol;
	}
};

int main()
{

}