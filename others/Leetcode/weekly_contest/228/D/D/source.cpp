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
	int minTrioDegree(int n, vector<vector<int>>& edges) {
		const int m = edges.size();
		vector<int> graph[401];
		int link[401][401] = { 0, };

		for (int i = 0; i < m; i++) {
			const int u = edges[i][0];
			const int v = edges[i][1];

			graph[u].push_back(v);
			graph[v].push_back(u);

			link[u][v] = link[v][u] = true;
		}

		int sol = 1000000000;

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < (int)graph[i].size() - 1; j++) {
				const int u = graph[i][j];

				/*
				if (i > u) {
					continue;
				}
				*/

				for (int k = j + 1; k < (int)graph[i].size(); k++) {
					const int v = graph[i][k];
					
					/*
					if (i > v || u > v) {
						continue;
					}
					*/

					if (link[u][v]) {
						sol = min(sol, (int)graph[i].size() + (int)graph[u].size() + (int)graph[v].size() - 6);
					}
				}
			}
		}

		if (sol == 1000000000) {
			return -1;
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	Solution s;
	vector<vector<int>> arr = { { 6,5 },{ 4,3 },{ 5,1 },{ 1,4 },{ 2,3 },{ 4,5 },{ 2,6 },{ 1,3 } };

	s.minTrioDegree(7, arr);

	return 0;
}