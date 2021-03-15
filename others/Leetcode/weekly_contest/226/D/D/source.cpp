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
	bool checkPartitioning(string s) {
		const int m = s.size();
		string str;

		for (int i = 0; i < m; i++) {
			str.push_back('#');

			str.push_back(s[i]);
		}

		str.push_back('#');

		int a[4004];
		int r = 0;
		int p = 0;
		a[0] = 0;

		const int n = m * 2 + 1;

		for (int i = 0; i < n; i++) {
			a[i] = min(r - i, a[p - a[p]]);

			for (int j = a[i] + 1; i - j >= 0 && i + j < n && str[i - j] == str[i + j]; j++) {
				a[i]++;
			}

			if (i + a[i] > r) {
				r = i + a[i];

				p = i;
			}
		}

		for (int i = 0; i < n; i++) {
			if (a[i] == i) {
				for (int j = a[i] + i + 1; j < n - 1; j++) {
					if (j - a[j] <= i + a[i] + 1) {
						const int k = j + (j - (a[i] + i) - 1);

						if (k != n - 1 && (k + n) / 2 + a[(k + n) / 2] == n - 1 && (k + n) / 2 - a[(k + n) / 2] == k + 1) {
							return true;
						}
					}
				}
			}
		}

		return false;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	Solution s;

	s.checkPartitioning("abcbdd");

	return 0;
}