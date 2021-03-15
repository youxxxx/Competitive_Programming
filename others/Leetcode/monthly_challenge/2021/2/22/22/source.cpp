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
	string findLongestWord(string s, vector<string>& d) {
		const int n = s.size();

		string sol;

		sort(d.begin(), d.end());

		for (int i = 0; i < (int)d.size(); i++) {
			const int m = d[i].size();

			if ((int)sol.size() < m) {
				int ptr = 0;

				for (int j = 0; j < n && ptr < m; j++) {
					if (d[i][ptr] == s[j]) {
						ptr++;
					}
				}

				if (ptr == m) {
					sol = d[i];
				}
			}
		}

		return sol;
	}
};