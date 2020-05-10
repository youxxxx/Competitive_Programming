#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> sumZero(int n) {
		vector<int> rvalue;

		for (int i = 1; i <= n/2; i++)
		{
			rvalue.push_back(i);
			rvalue.push_back(-i);
		}

		if (n % 2)
		{
			rvalue.push_back(0);
		}

		return rvalue;
	}
};

int main()
{
	Solution s;

	return 0;
}