#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

class Solution {
public:
	bool hasAllCodes(string s, int k) {
		bool check[1100000];

		const int n = s.size();
		const int ub = (int)pow(2.0, k);

		if (n <= k) {
			return false;
		}

		for (int i = 0; i < ub; i++) {
			check[i] = false;
		}

		int cur = 0;

		for (int i = 0; i < k; i++) {
			cur = cur * 2;
			cur += s[i] - '0';
			cur %= ub;
		}

		check[cur] = true;

		for (int i = k; i < n; i++) {
			cur = cur * 2;
			cur += s[i] - '0';
			cur %= ub;

			check[cur] = true;
		}

		for (int i = 0; i < ub; i++) {
			if (!check[i]) {
				return false;
			}
		}

		return true;
	}
};

int main()
{
	Solution s;
	s.hasAllCodes("01", 1);

	return 0;
}