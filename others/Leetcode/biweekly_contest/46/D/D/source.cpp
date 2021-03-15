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
	vector<int> last[51];
	int depth[100001];
	vector<int> graph[100001];
	vector<int> coprime[51];
	vector<int> sol;

	void dfs(int cur, int parent, int curdepth, vector<int>& nums) {
		depth[cur] = curdepth;

		for (int i = 0; i < (int)coprime[nums[cur]].size(); i++) {
			if (!last[coprime[nums[cur]][i]].empty()) {
				if (sol[cur] == -1 || depth[last[coprime[nums[cur]][i]].back()] > depth[sol[cur]]) {
					sol[cur] = last[coprime[nums[cur]][i]].back();
				}
			}
		}

		last[nums[cur]].push_back(cur);

		for (int i = 0; i < (int)graph[cur].size(); i++) {
			const int next = graph[cur][i];

			if (next == parent) {
				continue;
			}

			dfs(next, cur, curdepth + 1, nums);
		}

		last[nums[cur]].pop_back();
	}

	int gcd(int a, int b) {
		while (b) {
			a %= b;

			const int temp = a;
			a = b;
			b = temp;
		}

		return a;
	}

	vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
		const int n = nums.size();

		for (int i = 1; i <= 50; i++) {
			for (int j = 1; j <= 50; j++) {
				if (gcd(i, j) == 1) {
					coprime[i].push_back(j);
				}
			}

			//last[i] = -1;
		}

		for (int i = 0; i < n; i++) {
			sol.push_back(-1);
		}

		for (int i = 0; i < (int)edges.size(); i++) {
			const int u = edges[i][0];
			const int v = edges[i][1];

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		dfs(0, -1, 0, nums);

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}