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
	vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
		const int n = adjacentPairs.size();

		map<int, vector<pair<int, int>>> list;

		for (int i = 0; i < n; i++) {
			const int u = adjacentPairs[i][0];
			const int v = adjacentPairs[i][1];

			map<int, vector<pair<int, int>>>::iterator ret = list.find(u);
			if (ret == list.end()) {
				vector<pair<int, int>> emp;

				list[u] = emp;

				ret = list.find(u);
			}

			ret->second.push_back({ i,0 });

			ret = list.find(v);

			if (ret == list.end()) {
				vector<pair<int, int>> emp;

				list[v] = emp;

				ret = list.find(v);
			}

			ret->second.push_back({ i,1 });
		}

		int curval;
		pair<int, int> idx;

		for (map<int, vector<pair<int, int>>>::iterator it = list.begin(); it != list.end(); it++) {
			if ((int)it->second.size() == 1) {
				curval = it->first;

				idx = it->second[0];

				break;
			}
		}

		vector<int> sol;

		sol.push_back(curval);

		for (int i = 0; i < n; i++) {
			const int nextval = adjacentPairs[idx.first][!idx.second];

			sol.push_back(nextval);

			map<int, vector<pair<int, int>>>::iterator ret = list.find(nextval);

			if ((int)ret->second.size() == 1) {
				break;
			}

			pair<int, int> nextidx = { ret->second[0] };

			if (nextidx.first == idx.first) {
				nextidx = ret->second[1];
			}

			curval = nextval;
			idx = nextidx;
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}