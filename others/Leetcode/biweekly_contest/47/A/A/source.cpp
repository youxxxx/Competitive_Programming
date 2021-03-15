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
	int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
		const int n = points.size();

		int lmin = 1000000000;
		int sol = -1;

		for (int i = 0; i < n; i++) {
			const int nx = points[i][0];
			const int ny = points[i][1];

			if (nx == x || ny == y) {
				const int dist = abs(nx - x) + abs(ny - y);

				if (dist < lmin) {
					sol = i;

					lmin = dist;
				}
			}
		}

		return sol;
	}
};

int main()
{

}