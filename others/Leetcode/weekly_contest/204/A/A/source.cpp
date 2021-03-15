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
	bool containsPattern(vector<int>& arr, int m, int k) {
		const int n = arr.size();

		if (m*k > n) {
			return false;
		}

		for (int i = 0; i <= n - m*k; i++) {
			bool valid = true;

			for (int j = 0; j < m; j++) {
				for (int l = 0; l < k - 1; l++) {
					if (arr[i + l*m + j] != arr[i + (l + 1)*m + j]) {
						valid = false;

						break;
					}
				}

				if (!valid)	{
					break;
				}
			}

			if (valid) {
				return true;
			}
		}

		return false;
	}
};

int main()
{
	Solution s;
	vector<int> arr = { 1, 1 };

	s.containsPattern(arr, 1, 2);

	return 0;
}