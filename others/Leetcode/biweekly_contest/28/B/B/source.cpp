#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

class SubrectangleQueries {
public:
	int val[101][101];
	int n;
	int m;

	SubrectangleQueries(vector<vector<int>>& rectangle) {
		n = rectangle.size();
		m = rectangle[0].size();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)	{
				val[i][j] = rectangle[i][j];
			}
		}
	}

	void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
		for (int i = row1; i <= row2; i++) {
			for (int j = col1; j <= col2; j++) {
				val[i][j] = newValue;
			}
		}
	}

	int getValue(int row, int col) {
		return val[row][col];
	}
};

int main()
{


	return 0;
}