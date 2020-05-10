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
	int maxScore(string s) {
		const int n = s.size();

		int l = 0, r = 0;
		int lmax = 0;

		for (int i = n - 1; i >= 0; i--) {
			r += (s[i] == '1');
		}

		for (int i = 0; i < n - 1; i++) {
			l += (s[i] == '0');
			r -= (s[i] == '1');

			if (l + r > lmax) {
				lmax = l + r;
			}
		}

		return lmax;
	}
};

int main()
{
	Solution s;

	return 0;
}