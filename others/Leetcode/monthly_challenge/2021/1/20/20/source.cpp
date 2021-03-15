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
	bool isValid(string s) {
		const int n = s.size();

		int num[256];
		num['('] = 0;
		num[')'] = 0;
		num['['] = 1;
		num[']'] = 1;
		num['{'] = 2;
		num['}'] = 2;
		char left[256];
		left[')'] = '(';
		left[']'] = '[';
		left['}'] = '{';
		int cnt[3] = { 0, };
		stack<char> st;

		for (int i = 0; i < n; i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				cnt[num[s[i]]]++;

				st.push(s[i]);
			}

			else {
				if (!(cnt[num[s[i]]]--) || st.empty() || st.top() != left[s[i]]) {
					return false;
				}

				st.pop();
			}
		}

		for (int i = 0; i < 3; i++) {
			if (cnt[i]) {
				return false;
			}
		}

		return true;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}