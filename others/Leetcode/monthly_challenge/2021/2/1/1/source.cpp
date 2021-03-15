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
	int hammingWeight(uint32_t n) {
		int sol = 0;

		for (int i = 0; i < 32; i++) {
			sol += n % 2;

			n /= 2;
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}