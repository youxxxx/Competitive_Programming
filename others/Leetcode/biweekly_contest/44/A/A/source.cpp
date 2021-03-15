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
	int largestAltitude(vector<int>& gain) {
		int sol = 0;
		const int n = gain.size();
		int cur = 0;

		for (int i = 0; i < n; i++) {
			cur += gain[i];

			sol = max(sol, cur);
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}