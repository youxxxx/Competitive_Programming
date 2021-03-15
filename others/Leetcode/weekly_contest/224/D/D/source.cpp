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
	int state;
	int catrow, catcol, mouserow, mousecol, foodrow, foodcol;
	int n, m;

	void c2s() {
		state = (catrow * 8 + catcol) * 64 + (mouserow * 8 + mousecol);
	}

	void s2c() {
		catrow = state / 512;
		catcol = state % 512 / 64;
		mouserow = state % 64 / 8;
		mousecol = state % 8;
	}

	bool safe(int x, int y) {
		return x >= 0 && x < n&&y >= 0 && y < m;
	}

	bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
		const int dx[4] = { 0,0,-1,1 };
		const int dy[4] = { -1,1,0,0 };

		n = grid.size();
		m = grid[0].size();

		bool visited[10001] = { 0, };

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				switch (grid[i][j]) {
				case 'C':
					catrow = i;
					catcol = j;
					break;
				case 'M':
					mouserow = i;
					mousecol = j;
					break;
				case 'F':
					foodrow = i;
					foodcol = j;
					break;
				}
			}
		}

		c2s();

		queue<int> q;

		q.push(state);

		while (!q.empty()) {
			s2c();

			for (int i = 0; i < 4; i++) {

			}
		}
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}