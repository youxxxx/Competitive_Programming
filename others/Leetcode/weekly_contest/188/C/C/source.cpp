#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

class Solution {
public:
	vector<int> graph[100001];
	vector<int> children[100001];

	void dfs(int cur, int parent) {
		for (int i = 0; i < graph[cur].size(); i++) {
			const int next = graph[cur][i];

			if (next == parent) {
				continue;
			}

			children[cur].push_back(next);

			dfs(next, cur);
		}
	}

	int dfs2(int cur, vector<bool>& hasApple) {
		int sum = 0;

		for (int i = 0; i < children[cur].size(); i++) {
			const int next = children[cur][i];
			sum += dfs2(next, hasApple);
		}

		if (cur == 0) {
			return sum;
		}

		if (sum || hasApple[cur]) {
			return sum + 2;
		}

		return 0;
	}

	int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
		for (int i = 0; i < n - 1; i++) {
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
		}

		dfs(0, -1);

		return dfs2(0, hasApple);
	}
};

int main()
{
	return 0;
}