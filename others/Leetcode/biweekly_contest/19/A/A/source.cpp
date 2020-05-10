#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
	int numberOfSteps(int num) {
		int cnt = 0;

		while (num > 1) {
			cnt += num % 2 + 1;

			num /= 2;
		}
		
		if (num == 1)
		{
			cnt++;
		}

		return cnt;
	}
};

int main()
{
	Solution s;

	s.numberOfSteps(1);

	return 0;
}