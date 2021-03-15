#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

#define MOD 1000000007

using namespace std;

class Solution {
public:
	int numSplits(string s) {
		int lcnt[26] = { 0, };
		int rcnt[26] = { 0, };
		int left = 0, right = 0;
		const int n = s.size();

		for (int i = 0; i < n; i++) {
			rcnt[s[i] - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			right += !!rcnt[i];
		}

		int sol = 0;

		for (int i = 0; i < n; i++) {
			const int ch = s[i] - 'a';
			left += !(lcnt[ch]++);
			right -= !(--rcnt[ch]);

			sol += (left == right);
		}

		return sol;
	}
};

int main()
{

	return 0;
}