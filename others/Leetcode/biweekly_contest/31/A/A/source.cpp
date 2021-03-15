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
	int countOdds(int low, int high) {
		int sol = (high + 1) / 2 - low / 2;

		return sol;
	}
};

int main()
{

	return 0;
}