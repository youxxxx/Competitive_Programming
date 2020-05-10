#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	int numOfSubarrays(vector<int>& arr, int k, int threshold) {
		int cnt = 0;
		int sum = 0;
		int target;
		int n;

		n = arr.size();

		target = threshold*k;

		for (int i = 0; i < k; i++) {
			sum += arr[i];
		}

		cnt += (sum >= target);

		for (int i = k; i < n; i++) {
			sum -= arr[i - k];
			sum += arr[i];

			cnt += (sum >= target);
		}

		return cnt;
	}
};

int main()
{
	Solution s;

	s.numOfSubarrays({ 7,7,7,7,7,7,7 }, 7, 7);

	return 0;
}