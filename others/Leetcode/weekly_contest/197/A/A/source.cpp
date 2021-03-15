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
	int numIdenticalPairs(vector<int>& nums) {
		const int n = nums.size();
		int cnt[101] = { 0, };

		for (int i = 0; i < n; i++) {
			cnt[nums[i]]++;
		}

		int sol = 0;

		for (int i = 1; i <= 100; i++) {
			sol += cnt[i] * (cnt[i] - 1) / 2;
		}

		return sol;
	}
};

int main()
{


	return 0;
}