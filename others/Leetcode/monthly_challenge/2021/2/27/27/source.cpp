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
	int divide(int dividend, int divisor) {
		const long long bound = (long long)pow(2.0, 31);
		const long long sol = (long long)dividend / (long long)divisor;

		if (sol < -bound || sol >= bound)
		{
			return bound - 1;
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt","r",stdin);
}