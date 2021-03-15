#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

class Solution {
public:
	vector<int> finalPrices(vector<int>& prices) {
		const int n = prices.size();
		vector<int> sol;

		for (int i = 0; i < n; i++) {
			int val = prices[i];

			for (int j = i + 1; j < n; j++) {
				if (prices[j] <= prices[i]) {
					val -= prices[j];

					break;
				}
			}

			sol.push_back(val);
		}

		return sol;
	}
};

int main()
{


	return 0;
}