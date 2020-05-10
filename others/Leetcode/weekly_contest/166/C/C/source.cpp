#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int smallestDivisor(vector<int>& nums, int threshold) {
		int n;

		n = nums.size();

		int lb = 0, ub;
		int lmax = 0;

		for (int i = 0; i < n; i++)
		{
			if (nums[i] > lmax)
			{
				lmax = nums[i];
			}
		}

		ub = lmax;

		while (ub - lb >= 2)
		{
			int next;

			next = (lb + ub) / 2 + (lb + ub) % 2;

			int res = 0;

			for (int i = 0; i < n; i++)
			{
				res += (nums[i] + next - 1) / next;
			}

			if (res > threshold)
			{
				lb = next;
			}

			else
			{
				ub = next;
			}
		}

		return ub;
	}
};

int main()
{


	return 0;
}