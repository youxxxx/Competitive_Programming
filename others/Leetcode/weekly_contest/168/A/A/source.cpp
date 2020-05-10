#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int findNumbers(vector<int>& nums) {
		int n;

		n = nums.size();

		int rvalue = 0;

		for (int i = 0; i < n; i++) {
			int temp;

			temp = nums[i];

			int cnt = 0;

			while (temp) {
				temp /= 10;

				cnt++;
			}

			rvalue += !(cnt % 2);
		}

		return rvalue;
	}
};

int main()
{
	return 0;
}