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

	int largestSubmatrix(vector<vector<int>>& matrix) {
		const int n = matrix.size();
		const int m = matrix[0].size();
		int cur[100001] = { 0, };

		map<int,int> list;

		int sol = 0;

		for (int i = 0; i < n; i++) {
			int lmin = 100000;

			list.clear();

			for (int j = 0; j < m; j++) {
				if (matrix[i][j]) {
					cur[j]++;

					map<int, int>::iterator ret = list.find(cur[j]);

					if (ret == list.end()) {
						list[cur[j]] = 1;
					}

					else {
						ret->second++;
					}
				}

				else {
					cur[j] = 0;
				}
			}

			if (!list.empty()) {
				map<int, int>::iterator it = list.end();

				int acc = 0;

				do {
					it--;

					acc += it->second;

					sol = max(sol, acc*it->first);
				} while (it != list.begin());
			}
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}