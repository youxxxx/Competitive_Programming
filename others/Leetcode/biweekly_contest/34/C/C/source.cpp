#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<cstring>
#include<functional>

using namespace std;

#define MOD 1000000007

class Solution {
public:
	int findLengthOfShortestSubarray(vector<int>& arr) {
		const int n = arr.size();

		int ptr2 = 0;

		for (int i = n - 1; i >= 1; i--) {
			if (arr[i] < arr[i - 1]) {
				ptr2 = i;

				break;
			}
		}

		int sol = ptr2;

		for (int i = 0; i < n; i++) {
			if (i > 0 && arr[i - 1] > arr[i]) {
				break;
			}

			if (i >= ptr2) {
				return 0;
			}

			while (ptr2 != n&&arr[i] > arr[ptr2]) {
				ptr2++;
			}

			if (i >= ptr2) {
				return 0;
			}

			if (n - (i + 1 + (n - ptr2)) < sol) {
				sol = n - (i + 1 + (n - ptr2));
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