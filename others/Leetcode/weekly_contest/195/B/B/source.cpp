#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

class Solution {
public:
	bool canArrange(vector<int>& arr, int k) {
		const int n = arr.size();
		int cnt[100001] = { 0, };

		for (int i = 0; i < n; i++) {
			int val = arr[i] % k;

			if (arr[i] < 0) {
				int q = -arr[i] / k;

				val = (arr[i] + (q + 1)*k) % k;
			}

			cnt[val]++;
		}

		if (cnt[0] % 2) {
			return false;
		}

		if (!(k % 2) && cnt[k / 2] % 2) {
			return false;
		}

		for (int i = 1; i <= k / 2; i++) {
			if (cnt[i] != cnt[k - i]) {
				return false;
			}
		}

		return true;
	}
};

int main()
{
	Solution s;
	vector<int> arr = { 1, 2, 3, 4, 5, 6};

	s.canArrange(arr, 7);

	return 0;
}