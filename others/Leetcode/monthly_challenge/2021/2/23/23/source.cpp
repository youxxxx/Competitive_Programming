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
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		vector<int> left, right;
		const int n = matrix.size();
		const int m = matrix[0].size();

		for (int i = 0; i < n; i++) {
			left.push_back(matrix[i][0]);
			right.push_back(matrix[i][m - 1]);
		}

		const int lb = (int)(lower_bound(right.begin(), right.end(), target) - right.begin());
		const int ub = (int)(upper_bound(left.begin(), left.end(), target) - left.begin());

		for (int i = lb; i < ub; i++) {
			if (find(matrix[i].begin(), matrix[i].end(), target) != matrix[i].end()) {
				return true;
			}
		}

		return false;
	}
};