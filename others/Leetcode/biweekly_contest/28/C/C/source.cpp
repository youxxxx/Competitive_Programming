#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

class Solution {
public:
	int minSumOfLengths(vector<int>& arr, int target) {
		const int n = arr.size();
		int lmin[100001];
		int rmin[100001];

		if (n == 1) {
			return -1;
		}

		{
			int ptr = 0;
			int cur = 0;
			int curmin = -1;

			for (int i = 0; i < n; i++) {
				cur += arr[i];

				while (ptr < i && cur > target) {
					cur -= arr[ptr++];
				}

				if (cur == target) {
					if (curmin == -1 || i - ptr < curmin) {
						curmin = i - ptr;
					}
				}

				lmin[i] = curmin;
			}
		}

		{
			int ptr = n - 1;
			int cur = 0;
			int curmin = -1;

			for (int i = n - 1; i >= 0; i--) {
				cur += arr[i];

				while (ptr > i && cur > target) {
					cur -= arr[ptr--];
				}

				if (cur == target) {
					if (curmin == -1 || ptr - i < curmin) {
						curmin = ptr - i;
					}
				}

				rmin[i] = curmin;
			}
		}

		int sol = -1;

		for (int i = 0; i < n - 2; i++) {
			if (lmin[i] != -1 && rmin[i + 1] != -1) {
				if (sol == -1 || lmin[i] + rmin[i + 1] + 2 < sol) {
					sol = lmin[i] + rmin[i + 1] + 2;
				}
			}
		}

		return sol;
	}
};

int main()
{


	return 0;
}