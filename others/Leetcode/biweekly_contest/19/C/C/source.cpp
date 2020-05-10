#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	double angleClock(int hour, int minutes) {
		double rvalue;
		double h, m;

		h = (double)(hour%12) * 30 + (double)minutes / (double)2;
		m = (double)minutes*(double)6;

		rvalue = h - m + 360.0;

		if (rvalue > 360.0)
		{
			rvalue -= 360.0;
		}

		if (rvalue > 180.0)
		{
			rvalue = 360.0 - rvalue;
		}

		return rvalue;
	}
};

int main()
{
	Solution s;

	s.angleClock(12, 30);

	return 0;
}