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
	int cnt[501];
	vector<int> link[501];
	vector<int> children[501];
	bool dup;

	bool func(const pair<int, int> &a, const pair<int, int> &b) {
		return a.second > b.second;
	}

	bool func2(const int &a,const int &b) {
		return cnt[a] > cnt[b];
	}

	int dfs(int cur, int parent) {
		int ptr = 0;

		for (int i = 0; i < (int)link[parent].size() && link[parent][i] != parent; i++) {
			if ((int)link[cur].size() < i || link[parent][i] != link[cur][i]) {
				return 0;
			}

			ptr = i;
		}

		if (link[cur][ptr] != parent) {
			return 0;
		}

		ptr++;

		int ptr2 = ptr;

		while (link[parent][ptr2] != cur) {
			ptr2++;
		}		

		if ((int)link[parent].size() < (int)link[cur].size() + ptr2 - ptr) {
			return 0;
		}

		for (int i = ptr; i < (int)link[cur].size(); i++) {
		}
	}

	int checkWays(vector<vector<int>>& pairs) {
		memset(cnt, 0, sizeof(cnt));
		const int m = pairs.size();

		for (int i = 0; i < m; i++) {
			const int u = pairs[i][0];
			const int v = pairs[i][1];
			cnt[u]++;
			cnt[v]++;

			link[u].push_back(u);
			link[v].push_back(v);
			link[u].push_back(v);
			link[v].push_back(u);
		}

		vector<pair<int, int>> nodes;

		for (int i = 1; i <= 500; i++) {
			if (cnt[i]) {
				nodes.push_back({ i, cnt[i] });
			}
		}

		const int n = nodes.size();

		sort(nodes.begin(), nodes.end(), func);

		if (nodes[0].second != n - 1) {
			return 0;
		}

		for (int i = 0; i < n; i++) {
			const int u = nodes[i].first;

			sort(link[u].begin(), link[u].end(), func2);
		}

		dup = 0;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}