#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
		int n, m, k;

		n = mat.size();
		m = mat.front().size();
		k = K;

		int sum = 0;

		int arr[301][301];

		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < m + 2 * k; j++)
			{
				arr[i][j] = 0;
			}
		}

		for (int i = k; i < k + n; i++)
		{
			for (int j = 0; j < k; j++)
			{
				arr[i][j] = 0;
			}

			for (int j = k; j < m + k; j++)
			{
				arr[i][j] = mat[i - k][j - k];
			}

			for (int j = m + k; j < m + 2 * k; j++)
			{
				arr[i][j] = 0;
			}
		}

		for (int i = k + n; i < n + 2 * k; i++)
		{
			for (int j = 0; j < m + 2 * k; j++)
			{
				arr[i][j] = 0;
			}
		}

		int sol[101][101];

		int base = 0;

		for (int i = 0; i < 2 * k + 1; i++)
		{
			for (int j = 0; j < 2 * k + 1; j++)
			{
				base += arr[i][j];
			}
		}

		sol[0][0] = base;

		for (int i = 0; i < n; i++)
		{
			if (i > 0)
			{
				sol[i][0] = sol[i - 1][0];

				for (int l = 0; l < 2 * k + 1; l++)
				{
					sol[i][0] -= arr[i - k - 1 + k][l];
					sol[i][0] += arr[i + k + k][l];
				}
			}

			for (int j = 1; j < m; j++)
			{
				sol[i][j] = sol[i][j - 1];

				for (int l = 0; l < 2 * k + 1; l++)
				{
					sol[i][j] -= arr[l + i][j - 1];
					sol[i][j] += arr[l + i][j + 2 * k];
				}
			}
		}

		vector<vector<int>> rvalue;

		for (int i = 0; i < n; i++)
		{
			vector<int> cur;

			for (int j = 0; j < m; j++)
			{
				cur.push_back(sol[i][j]);
			}

			rvalue.push_back(cur);
		}

		return rvalue;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> mat = { { 1,2,3 },{ 4,5,6 },{ 7,8,9 } };

	s.matrixBlockSum(mat, 1);

	return 0;
}