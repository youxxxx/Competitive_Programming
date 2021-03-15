#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

class Solution {
public:
	vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		vector<int> out[101];
		int in[101] = { 0, };
		bool pre[101][101] = { 0, };

		const int m = prerequisites.size();

		for (int i = 0; i < m; i++) {
			pre[prerequisites[i][1]][prerequisites[i][0]] = true;

			out[prerequisites[i][0]].push_back(prerequisites[i][1]);
			in[prerequisites[i][1]]++;
		}
		
		queue<int> q;

		for (int i = 0; i < n; i++) {
			if (!in[i]) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			const int cur = q.front();
			q.pop();
			
			for (int i = 0; i < out[cur].size(); i++) {
				const int next = out[cur][i];

				for (int j = 0; j < n; j++) {
					pre[next][j] = pre[next][j] || pre[cur][j];
				}

				if (!(--in[next])) {
					q.push(next);
				}
			}
		}

		vector<bool> sol;

		for (int i = 0; i < queries.size(); i++) {
			int u, v;

			u = queries[i][0];
			v = queries[i][1];

			sol.push_back(pre[v][u]);
		}

		return sol;
	}
};

int main()
{
	Solution s;

	return 0;
}