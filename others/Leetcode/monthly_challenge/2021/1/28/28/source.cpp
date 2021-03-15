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
	string getSmallestString(int n, int k) {
		string sol;

		for (int i = 0; i < n; i++) {
			sol.push_back('a');
		}

		k -= n;

		for (int i = n - 1; i >= 0 && k; i--) {
			sol[i] += min(25, k);

			k -= min(25, k);
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}