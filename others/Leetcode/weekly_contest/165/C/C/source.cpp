#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
	int countSquares(vector<vector<int>>& matrix)
	{
		int acc[301][301];
		int n, m;

		n = matrix.size();
		m = matrix[0].size();

		int sol = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!matrix[i][j])
				{
					acc[i][j] = 0;
				}

				else
				{
					int lmin = 999;

					if (i > 0)
					{
						if (acc[i - 1][j] < lmin)
						{
							lmin = acc[i - 1][j];
						}
					}

					else
					{
						lmin = 0;
					}

					if (j > 0)
					{
						if (acc[i][j - 1] < lmin)
						{
							lmin = acc[i][j - 1];
						}
					}

					else
					{
						lmin = 0;
					}

					if (i > 0 && j > 0)
					{
						if (acc[i - 1][j - 1] < lmin)
						{
							lmin = acc[i - 1][j - 1];
						}
					}

					else
					{
						lmin = 0;
					}

					acc[i][j] = lmin + 1;

					sol += acc[i][j];
				}
			}
		}

		return sol;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> m= {
		{ 0,1,1,1 },
		{ 1,1,1,1 },
		{ 0,1,1,1 }
	};

	s.countSquares(m);
}