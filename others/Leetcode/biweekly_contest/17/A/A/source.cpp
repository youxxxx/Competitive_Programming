#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> decompressRLElist(vector<int>& nums) {
		int n;

		n = nums.size();

		vector<int> rvalue;

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < nums[i * 2]; j++) {
				rvalue.push_back(nums[i * 2 + 1]);
			}
		}

		return rvalue;
	}
};

int main()
{
	return 0;
}