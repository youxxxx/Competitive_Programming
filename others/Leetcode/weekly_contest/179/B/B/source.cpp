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
	int numTimesAllBlue(vector<int>& light) {
		int n;

		n = light.size();

		int val[50001] = { 0, };

		priority_queue<int, vector<int>, greater<int>> pq;
		int cur = 0;
		int sol = 0;

		for (int i = 0; i < n; i++) {
			pq.push(light[i]);

			while (!pq.empty() && pq.top() == cur + 1) {
				pq.pop();

				cur++;
			}

			if (pq.empty()) {
				sol++;
			}
		}

		return sol;
	}
};

int main()
{
	Solution s;
}