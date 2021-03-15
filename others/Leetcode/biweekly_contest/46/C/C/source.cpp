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

const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,1,0,0 };

class Solution {
public:
	int n;
	int m;

	bool safe(int x, int y) {
		return x >= 0 && x < n&&y >= 0 && y < m;
	}

	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		n = isWater.size();
		m = isWater[0].size();
		vector<vector<int>> sol;
		vector<int> emp;
		int lb[1001][1001];
		int ub[1001][1001];
		for (int i = 0; i < m; i++) {
			emp.push_back(-1);
		}

		for (int i = 0; i < n; i++) {
			sol.push_back(emp);
			
			for (int j = 0; j < m; j++) {
				lb[i][j] = 0;
				ub[i][j] = 1000000000;
			}
		}

		queue<pair<int, int>> q;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (isWater[i][j]) {
					sol[i][j] = 0;

					lb[i][j] = ub[i][j] = 0;

					q.push({ i,j });
				}
			}
		}

		while (!q.empty()) {
			const int x = q.front().first;
			const int y = q.front().second;
			q.pop();

			sol[x][y] = ub[x][y];

			const int left = max(0, sol[x][y] - 1);
			const int right = sol[x][y] + 1;

			for (int i = 0; i < 4; i++) {
				const int nx = x + dx[i];
				const int ny = y + dy[i];

				if (!safe(nx, ny)) {
					continue;
				}

				if (ub[nx][ny] == 1000000000) {
					q.push({ nx, ny });
				}

				lb[nx][ny] = max(lb[nx][ny], left);
				ub[nx][ny] = min(ub[nx][ny], right);
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