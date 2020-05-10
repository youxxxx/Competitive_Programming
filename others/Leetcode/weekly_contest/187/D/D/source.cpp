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

class comp {
public:
	bool operator()(const pair<int, vector<int>> &a, const pair<int, vector<int>> &b) {
		return a.first > b.first;
	}
};

class Solution {
public:
	int kthSmallest(vector<vector<int>>& mat, int k) {
		const int n = mat.size();
		const int m = mat[0].size();
		vector<int> base;
		int sum = 0;

		for (int i = 0; i < n; i++) {
			sum += mat[i][0];

			base.push_back(0);
		}

		priority_queue < pair<int, vector<int>>, vector<pair<int, vector<int>>>, comp> pq;
		set<vector<int>> list;

		pq.push({ sum,base });

		for (int i = 0; i < k - 1; i++) {
			pair<int, vector<int>> cur;

			cur = pq.top();
			pq.pop();

			for (int i = 0; i < n; i++) {
				if (cur.second[i] < m - 1) {
					cur.second[i]++;

					set<vector<int>>::iterator ret;

					ret = list.find(cur.second);

					if (ret == list.end()) {
						pq.push({ cur.first + mat[i][cur.second[i]] - mat[i][cur.second[i] - 1],cur.second });

						list.insert(cur.second);
					}
					
					cur.second[i]--;
				}
			}
		}

		return pq.top().first;
	}
};

int main() {
	Solution s;
	vector<vector<int>> arr = { { 1,3,11 },{ 2,4,6 } };

	s.kthSmallest(arr, 9);

	return 0;
}