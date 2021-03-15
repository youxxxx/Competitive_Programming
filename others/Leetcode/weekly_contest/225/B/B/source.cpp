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
	int minCharacters(string a, string b) {
		const int n = a.size();
		const int m = b.size();

		int cnt1[26] = { 0, };
		int cnt2[26] = { 0, };

		for (int i = 0; i < n; i++) {
			cnt1[a[i] - 'a']++;
		}

		for (int i = 0; i < m; i++) {
			cnt2[b[i] - 'a']++;
		}

		int racc1[26];
		int racc2[26];

		racc1[25] = cnt1[25];
		racc2[25] = cnt2[25];

		for (int i = 24; i >= 0; i--) {
			racc1[i] = racc1[i + 1] + cnt1[i];
			racc2[i] = racc2[i + 1] + cnt2[i];
		}

		int acc1 = 0;
		int acc2 = 0;

		int sol = n + m;

		for (int i = 0; i < 25; i++) {
			acc1 += cnt1[i];
			acc2 += cnt2[i];

			sol = min(sol, acc1 + racc2[i + 1]);
			sol = min(sol, acc2 + racc1[i + 1]);
		}

		for (int i = 0; i < 26; i++) {
			sol = min(sol, n + m - (cnt1[i] + cnt2[i]));
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}