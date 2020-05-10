#define _USE_MATH_DEFINES

#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

class Solution {
public:
	bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
		int x3, y3, x4, y4;

		x3 = x_center - radius;
		x4 = x_center + radius;
		y3 = y_center - radius;
		y4 = y_center + radius;

		if (x3 <= x1&&x4 >= x2&&y3 <= y1&&y4 >= y2)	{
			return true;
		}

		if (x3 > x2 || y3 > y2 || x4 < x1 || y4 < y1) {
			return false;
		}

		if (x_center >= x1 - radius && x_center <= x2 + radius && y_center >= y1&&y_center <= y2) {
			return true;
		}

		if (x_center >= x1 && x_center <= x2 && y_center >= y1 - radius &&y_center <= y2 + radius) {
			return true;
		}

		if ((x_center - x1)*(x_center - x1) + (y_center - y1)*(y_center - y1) <= radius*radius) {
			return true;
		}

		if ((x_center - x2)*(x_center - x2) + (y_center - y1)*(y_center - y1) <= radius*radius) {
			return true;
		}

		if ((x_center - x1)*(x_center - x1) + (y_center - y2)*(y_center - y2) <= radius*radius) {
			return true;
		}

		if ((x_center - x2)*(x_center - x2) + (y_center - y2)*(y_center - y2) <= radius*radius) {
			return true;
		}

		return false;
	}
};

int main()
{
	Solution s;

	return 0;
}