#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<cstring>

using namespace std;

class Solution {
public:
	int dist[101];
	double prob[101];
	int cnt[101] = { 0, };
	vector<int> graph[101];

	void dfs(int cur, int curdist,double curval) {
		cnt[curdist]++;
		double val;

		val = curval / (double)(graph[cur].size() - (cur != 1));

		for (int i = 0; i < graph[cur].size(); i++) {
			int next;

			next = graph[cur][i];

			if (dist[next] != -1) {
				continue;
			}

			dist[next] = curdist + 1;
			prob[next] = val;

			dfs(next, curdist + 1, val);
		}
	}
	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		
		for (int i = 0; i < n - 1; i++) {
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
		}

		memset(dist, -1, sizeof(dist));

		dist[1] = 0;
		prob[1] = 1.0;

		dfs(1, 0, 1.0);

		double rvalue = 0.0;

		if (dist[target] > t) {
			return rvalue;
		}

		if (dist[target] == t) {
			return prob[target];
		}

		if (graph[target].size() - (target != 1) == 0) {
			return prob[target];
		}

		return rvalue;
	}
};

int main()
{
	Solution s;

	vector<vector<int>> edges = { { 1,2 },{ 1,3 },{ 1,7 },{ 2,4 },{ 2,6 },{ 3,5 } };

	s.frogPosition(7, edges, 20, 6);
}