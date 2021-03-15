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
	int sol;
	vector<int> arr[16];
	bool taken[16];

	void dfs(int cur) {
		if (cur == 1) {
			sol++;

			return;
		}

		for (int i = 0; i < arr[cur].size(); i++) {
			const int next = arr[cur][i];

			if (!taken[next]) {
				taken[next] = true;

				dfs(cur - 1);

				taken[next] = false;
			}
		}
	}

	int countArrangement(int n) {

		sol = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!(i%j) || !(j%i)) {
					arr[i].push_back(j);
				}
			}

			taken[i] = false;
		}

		dfs(n);
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	return 0;
}