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
	const int dx[8] = { -1,-1,-1,0,0,1,1,1 };
	const int dy[8] = { -1,0,1,-1,1,-1,0,1 };
	int n;

	bool safe(int x, int y) {
		return x >= 0 && x < n&&y >= 0 && y < n;
	}

	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		if (grid[0][0] == 1) {
			return -1;
		}

		n = grid.size();

		int sol = 10001;

		int visited[101][101];

		memset(visited, -1, sizeof(visited));

		visited[0][0] = 1;

		queue<pair<int, int>> q;

		q.push({ 0,0 });

		while (!q.empty()) {
			const int x = q.front().first;
			const int y = q.front().second;
			q.pop();

			for (int i = 0; i < 8; i++) {
				const int nx = x + dx[i];
				const int ny = y + dy[i];

				if (safe(nx,ny) && !grid[nx][ny] && visited[nx][ny] == -1) {
					visited[nx][ny] = visited[x][y] + 1;

					q.push({ nx,ny });
				}
			}
		}

		return visited[n - 1][n - 1];
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}