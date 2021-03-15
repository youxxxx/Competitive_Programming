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
	static bool func(const vector<int> &a, const vector<int> &b) {
		return a[1] < b[1];
	}

	int maxValue(vector<vector<int>>& events, int k) {
		const int n = events.size();

		sort(events.begin(), events.end(), func);

		//int ptr = 0;
		pair<int, priority_queue<int>> dp[1000001];

		for (int i = 0; i < n; i++) {
			priority_queue<int> emp;
			dp[i] = { 0, emp };
		}

		int sol = 0;
		priority_queue<int> emp;
		//pair<int, priority_queue<int>> oneless = { 0,emp };

		for (int i = 0; i < n; i++) {
			int lb = -1, ub = i;

			for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)	{
				if (events[next][1] < events[i][0]) {
					lb = next;
				}

				else {
					ub = next;
				}
			}

			/*
			while (ptr < i&&events[ptr][1] < events[i][0]) {
				if ((int)dp[ptr].second.size() == k) {
					oneless = dp[ptr];

					oneless.first += oneless.second.top();

					oneless.second.pop();
				}

				else {
					oneless = dp[ptr];
				}

				ptr++;
			}
			*/

			if (ub < 1) {
				if (k > 1) {
					dp[i].first = events[i][2];
					dp[i].second.push(-events[i][2]);
				}

				sol = max(sol, events[i][2]);

				continue;
			}

			pair<int, priority_queue<int>> lmax;

			if (i > 0) {
				lmax = dp[i] = dp[i - 1];
			}

			if (dp[lb].first + events[i][2] > lmax.first) {
				lmax = dp[lb];

				lmax.first += events[i][2];

				lmax.second.push(-events[i][2]);
			}

			sol = max(sol, lmax.first);

			if ((int)lmax.second.size() == k) {
				lmax.first += lmax.second.top();

				lmax.second.pop();
			}

			if (lmax.first > dp[i].first) {
				dp[i] = lmax;
			}
		}

		return sol;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	Solution s;
	vector<vector<int>> arr = { { 1,1,1 },{ 2,2,2 },{ 3,3,3 },{ 4,4,4 } };

	s.maxValue(arr, 3);

	return 0;
}