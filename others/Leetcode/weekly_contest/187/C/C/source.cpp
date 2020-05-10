#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

class comp {
public:
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
		return a.first > b.first;
	}
};

class Solution {
public:
	int longestSubarray(vector<int>& nums, int limit) {
		const int n = nums.size();

		int sol = 1;

		priority_queue<pair<int, int>> g;
		priority_queue < pair<int, int>, vector < pair<int, int>>, comp > l;

		g.push({ nums[0],0 });
		l.push({ nums[0],0 });
		int last = -1;
		
		for (int i = 1; i < n; i++) {

			while (!g.empty() && (g.top().first - nums[i] > limit || g.top().second < last)) {
				if (g.top().second > last) {
					last = g.top().second;
				}

				g.pop();
			}

			while (!l.empty() && (nums[i] - l.top().first > limit || l .top().second < last)) {

				if (l.top().second > last) {
					last = l.top().second;
				}
				
				l.pop();
			}

			if (i - last > sol) {
				sol = i - last;
			}

			g.push({ nums[i],i });
			l.push({ nums[i],i });
		}

		return sol;
	}
};

int main() {
	Solution s;
	vector<int> arr = { 8,2,4,7 };

	s.longestSubarray(arr, 4);

	return 0;
}