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
	int minOperations(string s) {
		const int n = s.size();

		int sol = 0;

		for (int i = 0; i < n; i++)
		{
			sol += abs(s[i] - (i % 2 + '0'));
		}

		return min(sol, n - sol);
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}