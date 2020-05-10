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

#define MOD 1000000007

using namespace std;

class Solution {
public:
	int findGoodStrings(int n, string s1, string s2, string evil) {
		long long val1 = 0, val2 = 0;

		val1 = (val1 + s1[0] - '0') % MOD;
		val2 = (val2 + s2[0] - '0') % MOD;

		for (int i = 1; i < n; i++) {
			val1 = val1 * 26 % MOD;
			val2 = val2 * 26 % MOD;
			val1 = (val1 + s1[i] - '0') % MOD;
			val2 = (val2 + s2[i] - '0') % MOD;
		}

		long long base;

		base = (val2 - val1 + MOD) % MOD;

		long long subt

		for(int i=0;i<)
	}
};

int main()
{

	return 0;
}