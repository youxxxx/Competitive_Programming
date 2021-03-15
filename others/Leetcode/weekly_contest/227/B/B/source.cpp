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
	int maximumScore(int a, int b, int c) {
		if (a + b <= c) {
			return a + b;
		}

		if (b + c <= a) {
			return b + c;
		}

		if (c + a <= b) {
			return c + a;
		}

		return (a + b + c) / 2;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}