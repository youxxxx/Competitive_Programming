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
	vector<string> letterCasePermutation(string S) {
		const int n = S.size();
		vector<int> loc;
		
		for (int i = 0; i < n; i++) {
			if (!(S[i] >= '0'&&S[i] <= '9')) {
				if (S[i] >= 'a') {
					S[i] -= 32;
				}

				loc.push_back(i);
			}
		}

		const int m = loc.size();

		vector<string> sol;

		for (int i = 0; i < (1 << m); i++) {
			sol.push_back(S);

			for (int j = 0; j < m; j++) {
				if (i&(1 << j)) {
					sol.back()[loc[j]] += 32;
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