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
	const int dx[4] = { 0,0,-1,1 };
	const int dy[4] = { -1,1,0,0 };
	int n, m;

	bool safe(int x, int y) {
		return x >= 0 && x < n&&y >= 0 && y < m;
	}

	int minimumEffortPath(vector<vector<int>>& heights) {
		n = heights.size();
		m = heights[0].size();
		int lmin[101][101];
		int lb = min(heights[0][0], heights[n - 1][m - 1]);
		int ub = max(heights[0][0], heights[n - 1][m - 1]);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				lmin[i][j] = 1000000000;
			}
		}

		lmin[0][0] = 0;

		priority_queue<pair<int, pair<int, int>>> pq;

		pq.push({ ub - lb,{0,0} });

		while (!pq.empty()) {
			const int x = pq.top().second.first;
			const int y = pq.top().second.second;
			const int cur = -pq.top().first;
			pq.pop();

			if ((x == n - 1 && y == m - 1) || cur > lmin[x][y]) {
				continue;
			}

			for (int i = 0; i < 4; i++) {
				const int nx = x + dx[i];
				const int ny = y + dy[i];

				if (safe(nx, ny)) {
					const int next = max(cur, abs(heights[nx][ny] - heights[x][y]));

					if (next < lmin[nx][ny]) {
						lmin[nx][ny] = next;

						pq.push({ -next,{ nx,ny } });
					}
				}
			}
		}

		return lmin[n - 1][m - 1];
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}