#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<cstring>
#include<functional>

using namespace std;

#define MOD 1000000007

long long exp(long long base, long long pw) {
	long long rvalue = 1;

	while (pw) {
		if (pw % 2) {
			rvalue = rvalue*base%MOD;
		}

		base = base*base%MOD;

		pw /= 2;
	}

	return rvalue;
}

class Solution {
public:
	int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
		const int n = locations.size();
		vector<pair<int, int>> ordered;

		for (int i = 0; i < n; i++) {
			ordered.push_back({ locations[i],i });
		}

		sort(ordered.begin(), ordered.end());

		int loc[101];

		for (int i = 0; i < n; i++) {
			loc[ordered[i].second] = i;
		}

		long long dp[201][201] = { 0, };
		bool visited[201][201] = { 0, };

		visited[0][loc[start]] = true;
		dp[0][loc[start]] = 1;

		priority_queue<pair<int, int>> pq;

		pq.push({ 0,loc[start] });

		while (!pq.empty()) {
			const int curfuel = -pq.top().first;
			const int idx = pq.top().second;
			pq.pop();

			for (int i = 0; i < n; i++) {
				if (i == idx) {
					continue;
				}

				const int nfuel = curfuel + abs(ordered[idx].first - ordered[i].first);
				
				if (nfuel > fuel) {
					continue;
				}

				dp[nfuel][i] = (dp[nfuel][i] + dp[curfuel][idx]) % MOD;

				if (!visited[nfuel][i]) {
					visited[nfuel][i] = true;

					pq.push({ -nfuel, i });
				}
			}
		}

		long long sol = 0;

		for (int i = 0; i <= fuel; i++) {
			sol = (sol + dp[i][loc[finish]]) % MOD;
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	Solution s;
	vector<int> arr = { 2,3,6,8,4 };

	s.countRoutes(arr, 1, 3, 5);

	return 0;
}