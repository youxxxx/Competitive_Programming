#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<cstring>
#include<functional>

using namespace std;
class Solution {
public:
	int minCost(string s, vector<int>& cost) {
		const int n = cost.size();
		int sol = 0;
		int totcost;
		int lmax;
		int cnt = 1;

		totcost = lmax = cost[0];

		for (int i = 1; i < n; i++)	{
			if (s[i] != s[i - 1]) {

				if (cnt == 1) {
					totcost = lmax = cost[i];

					continue;
				}

				sol += totcost - lmax;

				totcost = lmax = cost[i];

				cnt = 1;
			}

			else {
				cnt++;

				totcost += cost[i];

				if (cost[i] > lmax) {
					lmax = cost[i];
				}
			}
		}

		if (cnt != 1) {
			sol += totcost - lmax;
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);


	return 0;
}