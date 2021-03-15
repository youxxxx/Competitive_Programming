#define _USE_MATH_DEFINES

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
	int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
		const double fangle = (double)angle / 180.0*M_PI;

		const int n = points.size();

		const int y = location[0];
		const int x = location[1];

		vector<double> arr;

		int base = 0;
		int sol = 0;

		for (int i = 0; i < n; i++) {
			const int ny = points[i][0] - y;
			const int nx = points[i][1] - x;

			if (!nx && !ny) {
				base++;

				continue;
			}

			if (!ny && nx < 0) {
				arr.push_back(M_PI);

				continue;
			}

			double val = atan2(ny, nx);

			if (val < 0.0) {
				val += M_PI * 2.0;
			}

			arr.push_back(val);
		}

		sort(arr.begin(), arr.end());

		const int m = arr.size();

		if (m == 1) {
			return base + 1;
		}

		int ptr = 0;

		for (int i = 0; i < m; i++) {
			while ((ptr + 1) % m != i && (arr[i] + fangle>=M_PI*2.0 && (arr[ptr] <= arr[i] + fangle - M_PI*2.0 || arr[ptr] >= arr[i]) || arr[i] + fangle < M_PI*2.0 && arr[ptr] <= arr[i] + fangle && arr[ptr] >= arr[i])) {
				ptr = (ptr + 1) % m;
			}

			int cand;

			if (ptr > i) {
				cand = ptr - i;
			}

			else {
				cand = (ptr + m - i);
			}

			if (arr[i] + fangle >= M_PI*2.0 && (arr[ptr] <= arr[i] + fangle - M_PI*2.0 || arr[ptr] >= arr[i]) || arr[i] + fangle < M_PI*2.0 && arr[ptr] <= arr[i] + fangle && arr[ptr] >= arr[i]) {
				cand++;
			}

			if (cand > sol) {
				sol = cand;
			}
		}

		return sol + base;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	Solution s;
	vector<vector<int>> arr = { { 1,1 },{ 2,2 },{ 1,2 },{ 2,1 } };
	vector<int> arr2 = { 1,1 };

	s.visiblePoints(arr, 0, arr2);

	return 0;
}