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
	int romanToInt(string s) {
		const int n = s.size();
		int val[255];
		val['M'] = 1000;
		val['D'] = 500;
		val['C'] = 100;
		val['L'] = 50;
		val['X'] = 10;
		val['V'] = 5;
		val['I'] = 1;

		int prev = 0;
		int sol = 0;

		for (int i = n - 1; i >= 0; i--)
		{
			const int cur = val[s[i]];

			if (cur < prev) {
				sol -= cur;
			}

			else {
				sol += cur;
			}

			prev = cur;
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}