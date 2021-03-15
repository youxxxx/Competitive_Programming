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
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

		const int n = mat.size();
		const int m = mat[0].size();

		for (int i = 0; i < n; i++) {
			vector<int> cur;

			for (int j = 0; j < m&&i + j < n; j++) {
				cur.push_back(mat[i + j][j]);
			}

			sort(cur.begin(), cur.end());

			for (int j = 0; j < m&&i + j < n; j++) {
				mat[i + j][j] = cur[j];
			}
		}

		for (int i = 1; i < m; i++) {
			vector<int> cur;

			for (int j = 0; j < n&&i + j < m; j++) {
				cur.push_back(mat[j][i + j]);
			}

			sort(cur.begin(), cur.end());

			for (int j = 0; j < n&&i + j < m; j++) {
				mat[j][i + j] = cur[j];
			}
		}

		return mat;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}