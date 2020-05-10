#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

class Solution {
public:
	int lmin = 9999999999999999;
	int lval = 0;
	int n;

	void bin_search(int lb, int ub, vector<int>& arr, int target)
	{
		int val = 0;
		int next;
		next = (lb + ub) / 2;

		if (ub - lb < 2) {

			for (int i = 0; i < n; i++) {
				if (arr[i] < next) {
					val += arr[i];
				}

				else {
					val += next;
				}
			}

			if (abs(target - val) < lmin) {
				lmin = abs(target - val);
				lval = next;
			}

			return;
		}


		for (int i = 0; i < n; i++) {
			if (arr[i] < next) {
				val += arr[i];
			}

			else {
				val += next;
			}
		}

		if (abs(target - val) < lmin) {
			lmin = abs(target - val);
			lval = next;
		}

		else if (abs(target - val) == lmin && next < lval)
		{
			lval = next;
		}

		if (val == target)
		{
			return;
		}

		if (val > target) {
			bin_search(lb, next, arr, target);
		}

		else {
			bin_search(next, ub, arr, target);
		}
	}

	int findBestValue(vector<int>& arr, int target) {
		
		n = arr.size();

		int lmax = 0;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] > lmax) {
				lmax = arr[i];
			}
		}

		bin_search(0, lmax + 1, arr, target);

		return lval;
	}
};

int main()
{
	Solution s;
	vector<int> arr = {60864, 25176, 27249, 21296, 20204};

	s.findBestValue(arr, 56803);

	return 0;
}