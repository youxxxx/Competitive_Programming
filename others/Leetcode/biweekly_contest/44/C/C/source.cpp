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
	vector<int> decode(vector<int>& encoded) {
		vector<int> arr;

		arr.push_back(0);

		const int n = encoded.size() + 1;

		for (int i = 0; i < n - 1; i++) {
			arr.push_back(arr.back() ^ encoded[i]);
		}

		int bit[20] = { 0, };

		for (int i = 1; i <= n; i++) {
			int temp = i;

			for (int j = 0; j < 20; j++) {
				if (temp % 2) {
					bit[j]++;
				}

				temp /= 2;
			}
		}

		for (int i = 0; i < n; i++) {
			int temp = arr[i];

			for (int j = 0; j < 20; j++) {
				if (temp % 2) {
					bit[j]--;
				}

				temp /= 2;
			}
		}

		int val = 0;
		int cur = 1;

		for (int i = 0; i < 20; i++) {
			if (bit[i]) {
				val ^= cur;
			}

			cur *= 2;
		}

		for (int i = 0; i < n; i++) {
			arr[i] ^= val;
		}

		return arr;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	vector<int> arr = { 3,1 };

	Solution s;

	s.decode(arr);

	return 0;
}