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
	bool checkPowersOfThree(int n) {
		while (n) {
			const int r = n % 3;

			if (r == 2) {
				return false;
			}

			n /= 3;
		}

		return true;
	}
};

int main()
{

}