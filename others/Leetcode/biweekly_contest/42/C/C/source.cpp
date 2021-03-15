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
	string maximumBinaryString(string binary) {
		const int n = binary.size();
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			cnt += binary[i] - '0';
		}

		if (cnt >= n - 1) {
			return binary;
		}

		string sol;

		for (int i = 0; i < n; i++) {
			sol.push_back('1');
		}

		int start = -1;
		int end = -1;
		int cnt2 = 0;

		for (int i = 0; i < n; i++) {
			if (start == -1) {
				if (binary[i] == '0') {
					start = i;
				}
			}

			else {
				if (end == -1) {
					end = i;
				}

				cnt2 += binary[i] - '0';
			}
		}

		if (end == -1) {
			sol[n - 1] = '0';
		}

		else {
			sol[n - cnt2 - 1] = '0';
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}