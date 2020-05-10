#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	string generateTheString(int n) {
		string res;

		if (n % 2) {
			for (int i = 0; i < n; i++) {
				res.push_back('a');
			}
		}

		else
		{
			for (int i = 0; i < n - 1; i++) {
				res.push_back('a');
			}

			res.push_back('b');
		}

		return res;
	}
};

int main()
{
	Solution s;
}