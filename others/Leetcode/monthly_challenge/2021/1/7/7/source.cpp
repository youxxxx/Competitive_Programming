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
	int lengthOfLongestSubstring(string s) {
		int prev[256];

		memset(prev, -1, sizeof(prev));

		const int n = s.size();

		int sol = 0;
		int left = -1;

		for (int i = 0; i < n; i++) {
			left = max(left, prev[s[i]]);

			sol = max(sol, (i - left));

			prev[s[i]] = i;
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}