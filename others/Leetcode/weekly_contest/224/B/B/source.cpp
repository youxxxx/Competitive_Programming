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
	int tupleSameProduct(vector<int>& nums) {
		map<int, int> list;
		const int n = nums.size();

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				map<int, int>::iterator ret = list.find(nums[i] * nums[j]);

				if (ret == list.end()) {
					list[nums[i] * nums[j]] = 1;
				}

				else {
					ret->second++;
				}
			}
		}

		int sol = 0;

		for (map<int, int>::iterator it = list.begin(); it != list.end(); it++) {
			sol += 4 * it->second*(it->second - 1);
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}