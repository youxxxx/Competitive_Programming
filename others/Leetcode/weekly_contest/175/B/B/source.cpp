#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int minSteps(string s, string t) {
		int n;

		n = s.size();

		int cnt[26] = { 0, };

		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
			cnt[t[i] - 'a']--;
		}

		int sol = 0;

		for (int i = 0; i < 26; i++) {
			sol += abs(cnt[i]);
		}

		return sol / 2;
	}
};

int main()
{
	Solution S;
	string s = "friend", t = "family";

	S.minSteps(s, t);

	return 0;
}