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
#include<unordered_set>

using namespace std;

class comp {
public:
	bool operator() (const pair<double, double> &a, const pair<double, double> &b) {
		return a.second > b.second;
	}
};

class Solution {
public:
	int numPoints(vector<vector<int>>& points, int r) {
		const int n = points.size();
		const double lr = r;
		int sol = 0;
		int lmin = 10000, lmax = -10000;

		for (int i = 0; i < n; i++) {
			if (points[i][0] < lmin) {
				lmin = points[i][0];
			}

			if (points[i][0] > lmax) {
				lmax = points[i][0];
			}
		}

		for (int i = lmin; i <= lmax; i++) {
			int lb, ub;
			vector<pair<double , double>> interv;
			const double x = (double)i;
			for (int j = 0; j < n; j++) {
				if (abs(points[j][1] - x)<=lr) {
					double dist = (double)sqrt(lr*lr - (double)(abs(points[j][1] - x))*(double)(abs(points[j][1] - x)));
					interv.push_back({ points[j][0] - dist,points[j][0] + dist });
				}
			}

			sort(interv.begin(), interv.end());

			double prev = -100000000;
			priority_queue<pair<double, double>,vector<pair<double,double>>, comp> pq;

			for (int j = 0; j < interv.size(); j++) {
				pq.push(interv[j]);

				while (!pq.empty() && pq.top().second < interv[j].first) {
					pq.pop();
				}

				if (pq.size() > sol) {
					sol = pq.size();
				}
			}
		}

		return sol;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> arr = { { -9,-2 },{ 11,-2 },{ 2,-14 },{ 12,13 },{ -18,19 },{ 1,-16 },{ -19,15 },{ 10,-7 },{ -20,-8 },{ 4,13 },{ 2,5 },{ -9,0 },{ -3,13 },{ 11,14 },{ 8,7 },{ -4,-6 },{ -15,-16 },{ -15,14 },{ 15,-6 } };

	s.numPoints(arr,15);

	return 0;
}
