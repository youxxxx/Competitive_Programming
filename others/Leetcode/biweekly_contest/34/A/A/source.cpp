#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<cstring>
#include<functional>

using namespace std;

class Solution {
public:
	int diagonalSum(vector<vector<int>>& mat) {
		const int n = mat.size();

		int rvalue = 0;

		for (int i = 0; i < n; i++)
		{
			rvalue += mat[i][i] + mat[i][n - 1 - i];
		}

		if (n % 2)
		{
			rvalue -= mat[n / 2][n / 2];
		}

		return rvalue;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);


	return 0;
}