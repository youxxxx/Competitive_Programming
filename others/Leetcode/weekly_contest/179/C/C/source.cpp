#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

class Solution {
public:
	vector<int> graph[100001];
	int N;

	int dfs(int cur, vector<int>& informTime) {
		int lmax = 0;

		for (int i = 0; i < graph[cur].size(); i++) {
			int next;
			int ret;

			next = graph[cur][i];

			ret = dfs(next, informTime);

			if (ret > lmax) {
				lmax = ret;
			}
		}

		return lmax + informTime[cur];
	}
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

		for (int i = 0; i < n; i++) {
			if (i == headID) {
				continue;
			}

			graph[manager[i]].push_back(i);
		}

		N = n;

		return dfs(headID, informTime);
	}
};

int main()
{
	Solution s;
}