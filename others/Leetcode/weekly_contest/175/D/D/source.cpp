#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

class Solution {
public:
	int taken[8][8];
	int n, m;
	vector<pair<int, int>> coord;
	int dx[4] = { 0,0,1,1 };
	int dy[5] = { -1,1,-1,1 };
	int lmax;

	Solution() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				taken[i][j] = 0;
			}
		}

		lmax = 0;
	}

	int safe(int x, int y) {
		return x >= 0 && x < n&&y >= 0 && y < m;
	}

	void dfs(vector<vector<char>>& seats,int cnt,int cur) {
		if (cur == coord.size()) {
			if (cnt > lmax) {
				lmax = cnt;
			}

			return;
		}

		int x, y;

		x = coord[cur].first;
		y = coord[cur].second;

		if (!taken[x][y]) {
			for (int i = 0; i < 4; i++) {
				int nx, ny;

				nx = x + dx[i];
				ny = y + dy[i];

				if (safe(nx, ny)) {
					taken[nx][ny]++;
				}
			}

			dfs(seats, cnt + 1, cur + 1);

			for (int i = 0; i < 4; i++) {
				int nx, ny;

				nx = x + dx[i];
				ny = y + dy[i];


				if (safe(nx, ny)) {
					taken[nx][ny]--;
				}
			}
		}

		dfs(seats, cnt, cur + 1);
	}

	int maxStudents(vector<vector<char>>& seats) {

		n = seats.size();
		m = seats[0].size();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (seats[i][j] == '.') {
					coord.push_back({ i,j });
				}
			}
		}

		dfs(seats, 0, 0);

		return lmax;
	}
};


int main()
{
	return 0;
}