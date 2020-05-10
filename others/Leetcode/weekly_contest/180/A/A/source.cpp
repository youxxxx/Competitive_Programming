#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstring>
#include<stack>
#include<queue>

class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		int n, m;

		n = matrix.size();
		m = matrix[0].size();

		int minrow[50], maxcol[50];

		for (int i = 0; i < n; i++) {
			int cur = 100001;
			int idx = 0;

			for (int j = 0; j < m; j++) {

				if (matrix[i][j] < cur) {
					cur = matrix[i][j];
					idx = j;
				}
			}

			minrow[i] = idx;
		}



		for (int i = 0; i < m; i++) {
			int cur = 0;
			int idx = 0;

			for (int j = 0; j < n; j++) {

				if (matrix[j][i] > cur) {
					cur = matrix[j][i];
					idx = j;
				}
			}

			maxcol[i] = idx;
		}

		vector<int> sol;

		for (int i = 0; i < n; i++) {
			if (maxcol[minrow[i]] == i)	{
				sol.push_back(matrix[i][minrow[i]]);
			}
		}

		return sol;
	}
};

using namespace std;

int main()
{
}