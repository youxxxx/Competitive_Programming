#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<cstring>
#include<functional>

using namespace std;

class Solution {
public:
	string modifyString(string s) {
		const int n = s.size();

		if (n == 1 && s[0] == '?') {
			return "a";
		}

		for (int i = 0; i < n; i++) {
			if (s[i] == '?') {
				if (i == 0) {
					for (int j = 'a'; j <= 'z'; j++) {
						if (s[i + 1] != j) {
							s[i] = j;

							break;
						}
					}
				}

				else if (i == n - 1) {
					for (int j = 'a'; j <= 'z'; j++) {
						if (s[i - 1] != j) {
							s[i] = j;

							break;
						}
					}
				}

				else {
					for (int j = 'a'; j <= 'z'; j++) {
						if (s[i - 1] != j&&s[i + 1] != j) {
							s[i] = j;

							break;
						}
					}
				}
			}
		}

		return s;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);


	return 0;
}