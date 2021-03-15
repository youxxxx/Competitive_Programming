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

#define MOD 1000000007

class Solution {
public:
	int concatenatedBinary(int n) {
		long long next = 2;
		long long sol = 0;

		for (int i = 1; i <= n; i++) {
			if (i == next) {
				next = next * 2;
			}

			sol = (sol*next%MOD + i) % MOD;
		}

		return (int)sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}