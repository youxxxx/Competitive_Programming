#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

class Solution {
public:
	int brokenCalc(int X, int Y) {
		int sol = 0;
		int lmax = 1;

		while (X < Y) {
			X *= 2;

			lmax *= 2;
			sol++;
		}

		int temp = X - Y;

		sol += temp / lmax;
		temp %= lmax;

		while (temp) {
			sol += temp % 2;
			
			temp /= 2;
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}