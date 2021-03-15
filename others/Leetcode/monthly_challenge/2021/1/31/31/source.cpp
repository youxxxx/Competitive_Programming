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
	void nextPermutation(vector<int>& nums) {
		const int n = nums.size();

		int prev = 0;
		int ptr = -1;

		for (int i = n - 1; i >= 0; i--) {
			if (nums[i] < prev) {
				ptr = i;

				break;
			}

			prev = nums[i];
		}

		if (ptr != -1) {
			for (int i = n - 1; i > ptr; i--) {
				if (nums[i] > nums[ptr]) {
					const int temp = nums[i];
					nums[i] = nums[ptr];
					nums[ptr] = temp;

					break;
				}
			}
		}

		for (int i = 1; i <= (n - ptr) / 2; i++) {
			const int temp = nums[ptr + i];
			nums[ptr + i] = nums[n - i];
			nums[n - i] = temp;
		}
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}