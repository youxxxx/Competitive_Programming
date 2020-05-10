#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
		int dist[100][100];

		memset(dist, -1, sizeof(dist));

		for (int i = 0; i < edges.size(); i++) {
			dist[edges[i][0]][edges[i][1]] = edges[i][2];
			dist[edges[i][1]][edges[i][0]] = edges[i][2];
		}

		for (int i = 0; i < n; i++) {
			dist[i][i] = 0;
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dist[i][k] != -1 && dist[k][j] != -1 && (dist[i][j] == -1 || dist[i][k] + dist[k][j] < dist[i][j])) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}

		int lmin = 101;
		int midx;

		for (int i = n - 1; i >= 0; i--) {
			int cnt = 0;

			for (int j = 0; j < n; j++) {
				if (dist[i][j] <= distanceThreshold) {
					cnt++;
				}
			}

			if (cnt < lmin) {
				lmin = cnt;
				midx = i;
			}
		}

		return midx;
	}
};

int main()
{
	Solution s;

	return 0;
}