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
	int maximumGain(string s, int x, int y) {
		const int n = s.size();
		char front = 'a';
		int large = x;
		int small = y;
		
		if (y > x) {
			front = 'b';
			large = y;
			small = x;
		}

		string cur;
		int sol = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] != 'a'&&s[i] != 'b') {
				int cnt[2] = { 0, };

				int lev = 0;
				int num = 0;

				for (int j = 0; j < (int)cur.size(); j++) {
					cnt[cur[j] - 'a']++;

					if (cur[j] == front) {
						lev++;
					}

					else {
						if (lev) {
							lev--;
							num++;
						}
					}
				}

				const int tot = min(cnt[0], cnt[1]);

				sol += large*num + small*(tot - num);

				cur.clear();
			}

			else {
				cur.push_back(s[i]);
			}
		}

		int cnt[2] = { 0, };

		int lev = 0;
		int num = 0;

		for (int j = 0; j < (int)cur.size(); j++) {
			cnt[cur[j] - 'a']++;

			if (cur[j] == front) {
				lev++;
			}

			else {
				if (lev) {
					lev--;
					num++;
				}
			}
		}

		const int tot = min(cnt[0], cnt[1]);

		sol += large*num + small*(tot - num);

		cur.clear();

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}