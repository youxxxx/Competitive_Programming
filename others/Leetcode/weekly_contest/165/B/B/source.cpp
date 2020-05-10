#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
	vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
	{
		vector<int> rvalue;

		if (tomatoSlices > cheeseSlices * 4 || tomatoSlices < cheeseSlices * 2)
		{
			return rvalue;
		}

		int x, y;
		int x2;

		x2 = tomatoSlices - cheeseSlices * 2;

		if (x2 % 2)
		{
			return rvalue;
		}

		x = x2 / 2;
		y = cheeseSlices - x;

		rvalue.push_back(x);
		rvalue.push_back(y);

		return rvalue;
	}
};