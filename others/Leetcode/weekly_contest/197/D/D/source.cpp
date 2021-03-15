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
	double getMinDistSum(vector<vector<int>>& positions) {
		double square = 0;

		const int n = positions.size();

		double coord[2];
		
		for (int i = 0; i < 2; i++) {
			double cur = 0.0;

			for (int j = 0; j < n; j++) {
				cur += (double)positions[j][i];
			}

			cur /= (double)n;

			double next = cur;

			long long coef[3] = { 0, };

			for (int j = 0; j < n; j++) {
				coef[0] += positions[j][i] * positions[j][i];
				coef[1] -= positions[j][i] * 2;
				coef[2]++;
			}

			do {
				cur = next;

				double divd = 0.0, divs = (double)coef[2] * cur*2.0 + (double)coef[1];

 				double base = 1.0;

				for (int j = 0; j < 2; j++) {
					divd += base*(double)coef[j];

					base *= cur;
				}

				next = cur - divs / divd;
			} while (abs(next - cur) >= 0.000000000001);

			coord[i] = next;
		}

		double sol = 0.0;

		for (int i = 0; i < n; i++) {
			double val = sqrt((coord[0] - positions[i][0])*(coord[0] - positions[i][0]) + (coord[1] - positions[i][1])*(coord[1] - positions[i][1]));

			sol += val;
		}

		return sol;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> arr = { { 0,1 },{ 1,0 },{ 1,2 },{ 2,1 } };

	s.getMinDistSum(arr);

	return 0;
}