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
	vector<int> shortestToChar(string s, char c) {
		const int n = s.size();
		vector<int> sol(n);

		int cur = n;

		for (int i = 0; i < n; i++) {
			if (s[i] == c) {
				cur = 0;
			}

			else {
				cur++;
			}

			sol[i] = cur;
		}

		cur = n;

		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == c) {
				cur = 0;
			}

			else {
				cur++;
			}

			sol[i] = min(sol[i], cur);
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}