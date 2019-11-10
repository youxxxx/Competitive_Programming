#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
	int oddCells(int n, int m, vector<vector<int>>& indices)
	{
		int t;
		int arr[51][51] = { 0, };

		t = indices.size();

		for (int i = 0; i < t; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[indices[i][0]][j]++;
			}

			for (int j = 0; j < n; j++)
			{
				arr[j][indices[i][1]]++;
			}
		}
		
		int sol = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				sol += arr[i][j] % 2;
			}
		}

		return sol;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> v = { { 1,1 },{ 0,0 } };

	s.oddCells(2, 2, v);

	return 0;
}