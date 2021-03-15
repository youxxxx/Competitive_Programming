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
	bool check(vector<int>& nums) {
		const int n = nums.size();

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			cnt += (nums[i] > nums[(i + 1) % n]);
		}

		return (cnt <= 1);
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}