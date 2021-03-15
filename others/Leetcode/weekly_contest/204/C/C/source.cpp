#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

class Solution {
public:
	const int dx[4] = { 0,-1,0,1 };
	const int dy[4] = { -1,0,1,0 };

	int n, m;

	bool safe(int x, int y) {
		return x >= 0 && x < n&&y >= 0 && y < m;
	}

	int visited[31][31];

	void dfs(vector<vector<int>>& grid, int x, int y) {
		for (int i = 0; i < 4; i++) {
			const int nx = x + dx[i];
			const int ny = y + dy[i];

			if (safe(nx, ny) && grid[nx][ny] == 1 && !visited[nx][ny]) {
				visited[nx][ny] = 1;

				dfs(grid, nx, ny);
			}
		}
	}

	int minDays(vector<vector<int>>& grid) {
		n = grid.size();
		m = grid[0].size();

		int cnt[5] = { 0, };
		int tot = 0;

		int comp = 0;
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && grid[i][j]) {
					visited[i][j] = 1;

					comp++;

					dfs(grid, i, j);
				}
			}
		}

		if (comp > 1)
		{
			return 0;
		}

		for (int i = 0; i < n; i++) {

			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 0) {
					continue;
				}

				int cur = 0;
				for (int k = 0; k < 4; k++) {
					const int nx = i + dx[k];
					const int ny = j + dy[k];

					if (safe(nx, ny) && grid[nx][ny] == 1) {
						cur++;
					}
				}

				cnt[cur]++;
				tot++;
			}
		}

		if (tot == 1) {
			return 1;
		}

		if (tot == 2 && cnt[1] == 2) {
			return 2;
		}

		for (int i = 0; i < 2; i++) {
			if (cnt[i]) {
				return i;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (grid[i][j] == 1) {
					grid[i][j] = 0;

					int cur = 0;
					memset(visited, 0, sizeof(visited));

					for (int k = 0; k < n; k++) {
						for (int l = 0; l < m; l++) {
							if (!visited[k][l] && grid[k][l]) {
								visited[k][l] = 1;

								if (++cur > comp) {
									return 1;
								}

								dfs(grid, k, l);
							}
						}
					}

					grid[i][j] = 1;
				}
			}
		}

		return 2;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> arr = { { 1,1,0,1,1 },{ 1,1,1,1,1 },{ 1,1,0,1,1 },{ 1,1,0,1,1 } };

	s.minDays(arr);

	return 0;
}