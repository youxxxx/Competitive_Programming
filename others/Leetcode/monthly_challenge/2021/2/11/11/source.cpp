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
	bool isAnagram(string s, string t) {
		const int n = s.size();
		const int m = t.size();

		if (n != m) {
			return false;
		}

		int cnt[26] = { 0, };

		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
			cnt[t[i] - 'a']--;
		}

		for (int i = 0; i < 26; i++) {
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