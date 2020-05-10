#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

class Solution {
public:
	bool canConstruct(string s, int k) {
		int cnt[26] = { 0, };
		int n;

		n = s.size();

		if (k > n) {
			return false;
		}

		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
		}

		int odd = 0;

		for (int i = 0; i < 26; i++) {
			odd += cnt[i] % 2;
		}

		if (k < odd) {
			return false;
		}

		return true;
	}
};

int main()
{
	Solution s;

	return 0;
}