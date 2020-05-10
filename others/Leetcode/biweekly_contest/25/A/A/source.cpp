#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

class Solution {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		const int n = candies.size();

		int lmax = 0;

		for (int i = 0; i < n; i++) {
			if (candies[i] > lmax) {
				lmax = candies[i];
			}
		}

		vector<bool> sol;

		for (int i = 0; i < n; i++) {
			if (candies[i] + extraCandies >= lmax) {
				sol.push_back(true);
			}

			else {
				sol.push_back(false);
			}
		}

		return sol;
	}
};

int main()
{

	return 0;
}