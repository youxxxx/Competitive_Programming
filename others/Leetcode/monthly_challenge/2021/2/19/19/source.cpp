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
	string minRemoveToMakeValid(string s) {
		const int n = s.size();
		vector<bool> valid;
		int cur = 0;

		for (int i = 0; i < n; i++) {
			valid.push_back(true);

			if (s[i] == ')') {
				if (!cur) {
					valid[i] = false;
				}

				else {
					cur--;
				}
			}

			else if (s[i] == '(') {
				cur++;
			}
		}

		cur = 0;

		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '(') {
				if (!cur) {
					valid[i]= false;
				}

				else {
					cur--;
				}
			}

			else if (s[i] == ')') {
				cur++;
			}
		}

		string sol;

		for (int i = 0; i < n; i++) {
			if (valid[i]) {
				sol.push_back(s[i]);
			}
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}