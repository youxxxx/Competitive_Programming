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
	int kthFactor(int n, int k) {
		int cnt = 0;

		for (int i = 1; i <= n; i++)
		{
			if (!(n%i))
			{
				cnt++;
			}

			if (cnt == k)
			{
				return i;
			}
		}

		return -1;
	}
};

int main()
{

	return 0;
}