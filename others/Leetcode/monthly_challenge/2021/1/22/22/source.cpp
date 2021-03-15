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
	bool closeStrings(string word1, string word2) {
		const int n = word1.size();
		const int m = word2.size();

		if (n != m) {
			return false;
		}

		int cnt1[26] = { 0, }, cnt2[26] = { 0, };

		for (int i = 0; i < n; i++) {
			cnt1[word1[i] - 'a']++;
			cnt2[word2[i] - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			if (cnt1[i] && !cnt2[i] || !cnt1[i] && cnt2[i]) {
				return false;
			}
		}

		sort(&cnt1[0], &cnt1[26]);
		sort(&cnt2[0], &cnt2[26]);

		for (int i = 0; i < 26; i++) {
			if (cnt1[i] != cnt2[i]) {
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