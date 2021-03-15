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
	int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
		priority_queue<pair<int, int>> pq;

		const int n = points.size();
		
		int ptr = 1;
		int sol = -2000000000;

		for (int i = 0; i < n; i++) {
			while (ptr < n&&points[ptr][0] - points[i][0] <= k) {
				pq.push({ points[ptr][1] + points[ptr][0],points[ptr][0] });
				ptr++;
			}

			while (!pq.empty() && pq.top().second <= points[i][0]) {
				pq.pop();
			}

			if (!pq.empty()) {
				if (pq.top().first - points[i][0] + points[i][1] > sol) {
					sol = pq.top().first - points[i][0] + points[i][1];
				}
			}
		}

		return sol;
	}
};

int main()
{
	Solution s;

	vector<vector<int>> arr = { { 1,3 },{ 2,0 },{ 5,10 },{ 6,-10 } };

	s.findMaxValueOfEquation(arr, 1);

	return 0;
}