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
#include<unordered_set>

using namespace std;

class Solution {
public:
	vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
		const int n = favoriteCompanies.size();
		unordered_set<string> list;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < favoriteCompanies[i].size(); j++) {
				list.insert(favoriteCompanies[i][j]);
			}
		}

		vector<vector<int>> arr;

		for (int i = 0; i < n; i++)	{
			vector<int> cur;
			unordered_set<string>::iterator ret;

			for (int j = 0; j < favoriteCompanies[i].size(); j++) {
				ret=list.find(favoriteCompanies[i][j]);

				cur.push_back(distance(list.begin(), ret));
			}

			sort(cur.begin(), cur.end());

			arr.push_back(cur);
		}

		vector<int> sol;

		for (int i = 0; i < n; i++) {
			bool valid = true;

			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}

				int ptr = 0;

				for (int k = 0; k < arr[j].size() && ptr < arr[i].size(); k++) {
					if (arr[j][k] == arr[i][ptr]) {
						ptr++;
					}
				}

				if (ptr == arr[i].size()) {
					valid = false;

					break;
				}
			}

			if (valid) {
				sol.push_back(i);
			}
		}

		return sol;
	}
};

int main()
{
	Solution s;
	vector<vector<string>> arr = { { "leetcode","google","facebook" },{ "google","microsoft" },{ "google","facebook" },{ "google" },{ "amazon" } };

	s.peopleIndexes(arr);

	return 0;
}