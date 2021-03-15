#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

class Solution {
public:
	int numWaterBottles(int numBottles, int numExchange) {
		int sol = 0;
		int empty = 0;

		int temp = numBottles;

		while (temp)
		{
			sol += temp;

			empty += temp;

			temp = empty / numExchange;

			empty %= numExchange;
		}

		return sol;
	}
};

int main()
{

	return 0;
}