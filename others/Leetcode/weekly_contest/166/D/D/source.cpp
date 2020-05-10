#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool safe(int x, int y, int n, int m)
{
	return x >= 0 && x < n&&y >= 0 && y < m;
}

class Solution {
public:
	int minFlips(vector<vector<int>>& mat)
	{
		int n, m;
		int dx[4] = { -1,0,1,0 };
		int dy[4] = { 0,-1,0,1 };

		n = mat.size();
		m = mat[0].size();

		int ub;

		ub = (int)pow(2.0, n * m);

		int lmin = -1;

		for (int i = 0; i < ub; i++)
		{
			int temp;
			int flip[3][3] = { 0, };
			int curmat[3][3];
			int cnt = 0;

			temp = i;

			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < m; k++)
				{
					curmat[j][k] = mat[j][k];
				}
			}

			for (int j = 0; j < n * m; j++)
			{
				int bit;

				bit = temp % 2;

				flip[j / m][j%m] = bit;

				cnt += bit;

				temp /= 2;
			}

			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < m; k++)
				{
					int nx, ny;

					if (flip[j][k])
					{
						curmat[j][k] = !curmat[j][k];

						for (int l = 0; l < 4; l++)
						{
							int nx, ny;

							nx = j + dx[l];
							ny = k + dy[l];

							if (safe(nx,ny,n,m))
							{
								curmat[nx][ny] = !curmat[nx][ny];
							}
						}
					}
				}
			}

			bool valid = true;

			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < m; k++)
				{
					if (curmat[j][k])
					{
						valid = false;

						break;
					}
				}

				if (!valid)
				{
					break;
				}
			}

			if (valid&&(lmin == -1 || cnt < lmin))
			{
				lmin = cnt;
			}
		}

		return lmin;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> mat = { { 0 },{ 1 },{ 1 } };

	s.minFlips(mat);

	return 0;
}