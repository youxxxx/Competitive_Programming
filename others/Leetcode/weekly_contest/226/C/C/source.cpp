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
	vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
		const int n = candiesCount.size();
		const int m = queries.size();

		vector<long long> acc;

		acc.push_back(0);

		for (int i = 0; i < n; i++) {
			acc.push_back(acc.back() + (long long)candiesCount[i]);
		}

		vector<bool> sol;

		for (int i = 0; i < m; i++) {
			const int type = queries[i][0];
			const long long day = queries[i][1];
			const long long cap = queries[i][2];

			sol.push_back((acc[type + 1] > day&&acc[type] - cap < day*cap));
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}