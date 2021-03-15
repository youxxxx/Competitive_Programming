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
	int numberOfArithmeticSlices(vector<int>& A) {
		const int n = A.size();

		if (n < 3) {
			return 0;
		}

		int sol = 0;
		int cur = A[1] - A[0];
		int cnt = 2;

		for (int i = 2; i < n; i++) {
			if (A[i] - A[i - 1] != cur) {
				sol += (cnt - 2)*(cnt - 1) / 2;

				cnt = 2;
				cur = A[i] - A[i - 1];
			}

			else {
				cnt++;
			}
		}

		sol += (cnt - 2)*(cnt - 1) / 2;

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}