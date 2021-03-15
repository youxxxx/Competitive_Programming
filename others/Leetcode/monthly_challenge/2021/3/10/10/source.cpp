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
	string intToRoman(int num) {
		vector<string> roman = { "MM","CD","XL","IV" };

		int base = 1000;

		string sol;

		for (int i = 0; i < 4; i++, base /= 10) {
			const int digit = num / base;
			num %= base;

			if (digit == 9) {
				sol.push_back(roman[i][0]);
				sol.push_back(roman[i - 1][0]);

				continue;
			}

			if (digit == 4) {
				sol.append(roman[i]);

				continue;
			}

			if (digit >= 5) {
				sol.push_back(roman[i][1]);
			}

			for (int j = 0; j < digit % 5; j++) {
				sol.push_back(roman[i][0]);
			}
		}

		return sol;
	}
};

int main()
{

}