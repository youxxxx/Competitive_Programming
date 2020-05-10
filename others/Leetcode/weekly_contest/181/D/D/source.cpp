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
	string longestPrefix(string s) {
		set<string> list;
		int n;

		n = s.size();

		string cur;

		for (int i = n - 1; i >= 0; i--) {
			cur.insert(cur.begin(), s[i]);

			list.insert(cur);
		}

		string check;
		int lmax = 0;

		for (int i = 0; i < n - 1; i++) {
			check.push_back(s[i]);

			set<string>::iterator ret;

			ret = list.find(check);

			if (ret != list.end()) {
				lmax = i + 1;
			}
		}

		return s.substr(0, lmax);
	}
};

int main()
{
	Solution s;
}