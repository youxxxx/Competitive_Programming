#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

class Solution {
public:
	int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
		int n;
		bool hold[2001] = { 0, };
		bool taken[2001] = { 0, };
		queue<int> q;

		n = status.size();

		for (int i = 0; i < initialBoxes.size(); i++) {
			if (status[initialBoxes[i]]) {
				taken[initialBoxes[i]] = true;
				q.push(initialBoxes[i]);
			}

			else {
				hold[initialBoxes[i]] = true;
			}
		}

		int sum = 0;

		while (!q.empty()) {
			int cur;

			cur = q.front();
			q.pop();

			sum += candies[cur];

			for (int i = 0; i < keys[cur].size(); i++) {
				int next;

				next = keys[cur][i];

				if (hold[next]) {
					taken[next] = true;
					status[next] = true;
					hold[next] = false;
					q.push(next);
				}

				else {
					status[next] = true;
				}
			}

			for (int i = 0; i < containedBoxes[cur].size(); i++) {
				int next;

				next = containedBoxes[cur][i];

				if (!taken[next] && status[next]) {
					taken[next] = true;

					q.push(next);
				}

				else {
					hold[next] = true;
				}
			}
		}

		return sum;
	}
};

int main()
{
	return 0;
}