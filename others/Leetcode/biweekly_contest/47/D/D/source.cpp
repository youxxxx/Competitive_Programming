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

#define N 100001

class Solution {
public:
	int tree[N + 2];

	void add(int idx, int val) {
		if (idx <= 0) {
			return;
		}

		for (; idx <= N; idx += idx&(-idx)) {
			tree[idx] += val;
		}
	}

	int get(int idx){
		if (idx <= 0) {
			return 0;
		}

		int rvalue = 0;

		for (; idx; idx -= idx&(-idx)) {
			rvalue += tree[idx];
		}

		return rvalue;
	}

	int psum(int r, int l) {
		return get(r) - get(l);
	}

	vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
		vector<int> graph[N + 1];

		for (int i = 0; i < (int)edges.size(); i++)	{
			const int u = edges[i][0];
			const int v = edges[i][1];

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		const int m = queries.size();

		vector<int> sol(m);

			memset(tree, 0, sizeof(tree));

			//const int bound = queries[i];

			int cnt[N + 1];

			for (int j = 1; j <= n; j++) {
				cnt[j] = (int)graph[j].size();

				add(cnt[j] + 1, 1);
			}

			int cur = 0;

			for (int j = 1; j <= n; j++) {
				add(cnt[j] + 1, -1);

				for (int k = 0; k < (int)graph[j].size(); k++) {
					const int v = graph[j][k];

					if (v < j) {
						continue;
					}

					add(cnt[v] + 1, -1);
					add(--cnt[v] + 1, 1);
				}

				for (int k = 0; k < m; k++) {
					sol[k] += psum(N, max(0, queries[k] + 1 - cnt[j]));
				}
				

				for (int k = 0; k < (int)graph[j].size(); k++) {
					const int v = graph[j][k];

					if (v < j) {
						continue;
					}

					add(cnt[v] + 1, -1);
					add(++cnt[v] + 1, 1);
				}
			}

		return sol;
	}
};

int main()
{
	int n = 4;
	vector<vector<int>> edges = { { 1,2 },{ 2,4 },{ 1,3 },{ 2,3 },{ 2,1 } };
	vector<int> query = { 2,3 };
	Solution s;

	s.countPairs(n, edges, query);
}