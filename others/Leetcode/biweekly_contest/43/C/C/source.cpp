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
	vector<int> sol;
	bool used[21];
	bool rec(int cur ,int n, int idx) {
		if (cur == n) {
			return true;
		}

		while (sol[idx]) {
			idx++;
		}

		for (int i = n; i >= 1; i--) {
			if (!used[i] && !sol[idx] && (i == 1 || idx + i < n * 2 - 1 && !sol[idx+i])) {
				used[i] = true;
				sol[idx] = i;
				if (i != 1) {
					sol[idx + i] = i;
				}
				if (rec(cur + 1, n, idx + 1)) {
					return true;
				}
				if (i != 1) {
					sol[idx + i] = 0;
				}
				sol[idx] = 0;
				used[i] = false;
			}
		}

		return false;
	}

	vector<int> constructDistancedSequence(int n) {
		for (int i = 0; i < n * 2 - 1; i++) {
			sol.push_back(0);
		}

		for (int i = 1; i <= n; i++) {
			used[i + 1] = false;
		}

		rec(0, n, 0);

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);
	Solution s;
	s.constructDistancedSequence(2);

	return 0;
}