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
	const int dx[3] = { -1,0,1 };

	bool safe(int x, int n) {
		return x >= 0 && x < n;
	}
	int cherryPickup(vector<vector<int>>& grid) {
		int left[71][71] = { 0, }, right[71][71] = { 0, };

		const int n = grid.size();
		const int m = grid[0].size();

		left[0][0] = grid[0][0];

		int lmax = 0;

		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= i && j < m; j++) {
				for (int k = 0; k < 3; k++) {
					const int x = j + dx[k];

					if (safe(x, m) && left[i - 1][x] + grid[i][j] > left[i][j]) {
						left[i][j] = left[i - 1][x] + grid[i][j];

						if (left[i][j] > lmax) {
							lmax = left[i][j];
						}
					}
				}
			}
		}

		int lacc[71][71] = { 0, };

		for (int i = 0; i < n; i++) {
			int curmax = 0;

			for (int j = 0; j < m; j++) {
				if (left[i][j] > curmax) {
					curmax = left[i][j];
				}

				lacc[i][j] = curmax;
			}
		}

		right[0][m - 1] = grid[0][m - 1];

		int rmax = 0;

		for (int i = 1; i < n; i++) {
			for (int j = m - 1; j >= m - 1 - i && j >= 0; j--) {
				for (int k = 0; k < 3; k++) {
					const int x = j + dx[k];
					int add = 0;

					/*
					if (j > 0) {
						add = acc[i][j - 1];
					}
					*/

					if (safe(x, m) && right[i - 1][x] + grid[i][j] + add > right[i][j]) {
						right[i][j] = right[i - 1][x] + grid[i][j] + add;

						if (right[i][j] > rmax) {
							rmax = right[i][j];
						}
					}
				}
			}
		}

		int racc[71][71] = { 0, };

		for (int i = 0; i < n; i++) {
			int curmax = 0;

			for (int j = m - 1; j >= 0; j--) {
				if (right[i][j] > curmax) {
					curmax = right[i][j];
				}

				racc[i][j] = curmax;
			}
		}

		int tot[71][71] = { 0, };

		tot[0][0] = lacc[0][0] + racc[0][1];
		tot[0][m - 1] = lacc[0][m - 2] + racc[0][m - 1];
		for (int j = 1; j < m - 1; j++) {
			tot[0][j] = lacc[0][j - 1] + racc[0][j];

			if (lacc[0][j] + racc[0][j + 1] > tot[0][j]) {
				tot[0][j] = lacc[0][j] + racc[0][j + 1];
			}
		}

		int sol = 0;

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				/*
				if (j > 0) {
					if (lacc[i][j - 1] + racc[i][j] > tot[i][j]) {
						tot[i][j] = lacc[i][j - 1] + racc[i][j];
					}
				}

				if (j < m - 1) {
					if (lacc[i][j] + racc[i][j + 1] > tot[i][j]) {
						tot[i][j] = lacc[i][j] + racc[i][j + 1];
					}
				}
				*/

				for (int k = 0; k < 3; k++) {
					const int x = j + dx[k];

					if (safe(x, m) && tot[i - 1][x] + grid[i][j] > tot[i][j]) {
						tot[i][j] = tot[i - 1][x] + grid[i][j];
					}
				}

				if (tot[i][j] > sol) {
					sol = tot[i][j];
				}
			}
		}

		return sol;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> arr = { { 3,1,1 },{ 2,5,1 },{ 1,5,5 },{ 2,1,1 } };

	s.cherryPickup(arr);

	return 0;
}