#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class comp {
public:
	bool operator()(const vector<int> &a, const vector<int> &b) {
		return a[1] < b[1] || a[1] == b[1] && a[0] < b[0];
	}
};

class Solution {
public:
	vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
		int n;

		n = restaurants.size();

		priority_queue<vector<int>, vector<vector<int>>, comp> pq;

		for (int i = 0; i < n; i++) {
			if ((!veganFriendly || restaurants[i][2]) && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) {
				pq.push(restaurants[i]);
			}
		}

		vector<int> rvalue;

		while (!pq.empty()) {
			rvalue.push_back(pq.top()[0]);

			pq.pop();
		}

		return rvalue;
	}
};