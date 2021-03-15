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
	string longestNiceSubstring(string s) {
		const int n = s.size();

		string sol;

		for (int i = 0; i < n - 1; i++) {

			for (int j = i + 1; j < n; j++) {
				int cnt[255];

				for (char z = 'A'; z <= 'Z'; z++) {
					cnt[z] = cnt[z + 32] = 0;
				}

				for (int z = i; z <= j; z++) {
					cnt[s[z]]++;
				}

				bool valid = true;

				for (char z = 'A'; z <= 'Z'; z++) {
					if (!cnt[z] && cnt[z + 32] || cnt[z] && !cnt[z + 32]) {
						valid = false;

						break;
					}
				}

				if (valid && j - i + 1 > (int)sol.size()) {
					sol = s.substr(i, (j - i + 1));
				}
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