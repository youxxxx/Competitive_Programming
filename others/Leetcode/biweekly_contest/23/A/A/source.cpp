#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

class Solution {
public:
	int countLargestGroup(int n) {
		int cnt[40] = { 0, };
		int lmax = 0;

		for (int i = 1; i <= n; i++) {
			int temp;

			temp = i;
			int val = 0;

			while (temp) {
				val += temp % 10;

				temp /= 10;
			}

			if (++cnt[val] > lmax) {
				lmax = cnt[val];
			}
		}

		int sol = 0;

		for (int i = 1; i < 40; i++) {
			if (cnt[i] == lmax) {
				sol++;
			}
		}

		return sol;
	}
};

int main()
{
	Solution s;

	return 0;
}