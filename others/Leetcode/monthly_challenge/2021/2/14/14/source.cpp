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
	int color[101];

	bool dfs(int cur, int curcolor, vector<vector<int>>& graph) {
		for (int i = 0; i < (int)graph[cur].size(); i++) {
			const int next = graph[cur][i];

			if (color[next] == curcolor) {
				return false;
			}

			if (color[next] == -1) {
				color[next] = !curcolor;

				if (!dfs(next, !curcolor,graph)) {
					return false;
				}
			}
		}

		return true;
	}

	bool isBipartite(vector<vector<int>>& graph) {

		const int n = graph.size();

		memset(color, -1, sizeof(color));

		for (int i = 0; i < n; i++) {
			if (color[i] == -1) {
				if (!dfs(i, 0, graph)) {
					return false;
				}
			}
		}

		return true;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}