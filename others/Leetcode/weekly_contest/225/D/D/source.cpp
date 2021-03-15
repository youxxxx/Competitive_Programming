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
	int minimumBoxes(int n) {
		int lb = 0;
		int ub = n;

		vector<int> blocks = { 0 };

		for (int i = 1; blocks[i - 1] <= 1000000000; i++) {
			blocks.push_back(blocks.back() + i);
		}

		for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2) {
			int temp = n;
			int prev = next;
			int cur = next;

			while (cur && temp) {
				vector<int>::iterator ret = lower_bound(blocks.begin(), blocks.end(), cur), ret2;

				ret2 = ret;
				ret2--;

				cur = max(0, *ret2 - (*ret - cur));

				temp = max(0, temp - prev);

				prev = cur;
			}

			if (!temp) {
				ub = next;
			}

			else {
				lb = next;
			}
		}

		return ub;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	Solution s;

	s.minimumBoxes(10);

	return 0;
}