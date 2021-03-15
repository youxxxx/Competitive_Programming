#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

class Solution {
public:
	vector<int> graph[100001];
	int sol[100001];
	int cnt[100001][26];

	void dfs(int cur, string &labels, int parent) {
		for (int i = 0; i < 26; i++) {
			cnt[cur][i] = 0;
		}

		cnt[cur][labels[cur] - 'a'] = 1;

		for (int i = 0; i < graph[cur].size(); i++) {
			const int next = graph[cur][i];

			if (next == parent) {
				continue;
			}

			dfs(next, labels, cur);

			for (int j = 0; j < 26; j++) {
				cnt[cur][j] += cnt[next][j];
			}
		}

		sol[cur] = cnt[cur][labels[cur] - 'a'];
	}

	vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

		for (int i = 0; i < n - 1; i++) {
			const int u = edges[i][0];
			const int v = edges[i][1];

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		dfs(0, labels, -1);

		vector<int> rvalue;

		for (int i = 0; i < n; i++) {
			rvalue.push_back(sol[i]);
		}

		return rvalue;
	}
};

int main()
{

	return 0;
}