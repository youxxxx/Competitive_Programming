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
	int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
		const int m = friendships.size();
		const int l = languages.size();

		bool link[501][501];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < l; j++) {
				link[i][j] = false;
			}
		}

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < (int)languages[i].size(); j++) {
				link[languages[i][j] - 1][i] = true;
			}
		}

		bool check[501];

		for (int i = 0; i < l; i++) {
			check[i] = false;
		}

		for (int i = 0; i < m; i++) {
			const int u = friendships[i][0] - 1;
			const int v = friendships[i][1] - 1;

			bool valid = true;

			for (int j = 0; j < n; j++) {
				if (link[j][u] && link[j][v]) {
					valid = false;

					break;
				}
			}

			if (valid) {
				check[u] = check[v] = true;
			}
		}

		vector<int> add;

		for (int i = 0; i < l; i++) {
			if (check[i]) {
				add.push_back(i);
			}
		}

		int sol = (int)add.size();

		for (int i = 0; i < n; i++) {
			int cur = 0;

			for (int j = 0; j < add.size(); j++) {

				cur += !link[i][add[j]];
			}

			sol = min(sol, cur);
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	Solution s;

	vector<vector<int>> arr = { { 2 },{ 1,3 },{ 1,2 },{ 3 } };
	vector<vector<int>> arr2 = { { 1,4 },{ 1,2 },{ 3,4 },{ 2,3 } };

	s.minimumTeachings(3, arr, arr2);

	return 0;
}