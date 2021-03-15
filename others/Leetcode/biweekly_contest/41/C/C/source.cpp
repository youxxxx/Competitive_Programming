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
	int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
		const int n = aliceValues.size();

		vector<pair<int,int>> sum;

		for (int i = 0; i < n; i++) {
			sum.push_back({ -(aliceValues[i] + bobValues[i]),i });
		}

		sort(sum.begin(), sum.end());

		int sol = 0;

		for (int i = 0; i < n; i++) {
			if (!(i % 2)) {
				sol += aliceValues[sum[i].second];
			}

			else {
				sol -= bobValues[sum[i].second];
			}
		}

		if (sol != 0) {
			sol /= abs(sol);
		}

		return sol;
	}
};

int main()
{

	return 0;
}