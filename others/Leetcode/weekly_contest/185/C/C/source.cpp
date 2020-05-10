#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

class Solution {
public:
	int minNumberOfFrogs(string croakOfFrogs) {
		const int n = croakOfFrogs.size();
		int cnt[5] = { 0, };
		int val[255] = { 0, };

		val['c'] = 0;
		val['r'] = 1;
		val['o'] = 2;
		val['a'] = 3;
		val['k'] = 4;

		int lmax = 1;

		for (int i = 0; i < n; i++) {
			int idx;

			idx = val[croakOfFrogs[i]];

			cnt[idx]++;

			for (int j = 0; j < idx; j++) {
				if (cnt[j] < cnt[idx]) {
					return -1;
				}
			}

			if (cnt[idx] - cnt[4] > lmax) {
				lmax = cnt[idx] - cnt[4];
			}
		}

		if (cnt[0] != cnt[4]) {
			return -1;
		}
		
		return lmax;
	}
};

int main()
{
	Solution s;

	s.minNumberOfFrogs("crcoakroak");

	return 0;
}