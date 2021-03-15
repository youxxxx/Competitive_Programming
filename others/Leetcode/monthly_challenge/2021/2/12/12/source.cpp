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
	int numberOfSteps(int num) {
		int sol = 0;

		while (num) {
			sol += 1 + num % 2;

			num /= 2;
		}

		return sol - !!sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}