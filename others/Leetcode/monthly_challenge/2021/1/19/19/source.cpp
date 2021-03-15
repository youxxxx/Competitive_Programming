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
	string longestPalindrome(string s) {
		const int m = s.size();
		string str;

		for (int i = 0; i < m; i++) {
			str.push_back('#');

			str.push_back(s[i]);
		}

		str.push_back('#');

		int a[2002];
		int r = 0;
		int p = 0;
		a[0] = 0;

		const int n = m * 2 + 1;

		for (int i = 0; i < n; i++) {
			a[i] = min(r - i, a[p - a[p]]);

			for (int j = a[i] + 1; i - j >= 0 && i + j < n && str[i-j] == str[i+j]; j++) {
				a[i]++;
			}

			if (i + a[i] > r) {
				r = i + a[i];

				p = i;
			}
		}

		string sol;

		int lmax = 0;
		int midx = 0;

		for (int i = 0; i < n; i++) {
			if (a[i] > lmax) {
				lmax = a[i];
				midx = i;
			}
		}

		if (str[midx - lmax] == '#') {
			for (int i = midx - lmax + 1; i < midx + lmax; i += 2) {
				sol.push_back(str[i]);
			}
		}

		else {
			for (int i = midx - lmax; i < midx + lmax; i += 2) {
				sol.push_back(str[i]);
			}
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	Solution s;

	s.longestPalindrome("babad");

	return 0;
}