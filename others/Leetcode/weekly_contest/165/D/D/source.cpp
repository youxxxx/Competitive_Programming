#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:

	int palindromePartition(string s, int k)
	{
		int rec[101][101][101];

		memset(rec, -1, sizeof(rec));

		rec[0][1][1] = 0;

		int n;

		n = s.size();

		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j <= i + 1 && j <= k; j++)
			{
				int lmin = 9999;

				for (int l = 1; l <= n; l++)
				{
					if (rec[i - 1][j - 1][l] == -1)
					{
						break;
					}

					int cnt = 0;

					for (int z = 1; z <= l / 2; z++)
					{
						cnt += (s[i - z] != s[i - (l - z + 1)]);
					}

					if (rec[i - 1][j - 1][l] + cnt < lmin)
					{
						lmin = rec[i - 1][j - 1][l] + cnt;
					}
				}

				rec[i][j][1] = lmin;

				for (int l = 2; l <= n; l++)
				{
					if (rec[i - 1][j][l - 1] == -1)
					{
						break;
					}

					rec[i][j][l] = rec[i - 1][j][l - 1];
				}
			}
		}

		int lmin = 9999;

		for (int l = 1; l <= n; l++)
		{
			if (rec[n - 1][k][l] == -1)
			{
				break;
			}

			int cnt = 0;

			for (int z = 1; z <= l / 2; z++)
			{
				cnt += (s[n - z] != s[n - (l - z + 1)]);
			}

			if (rec[n - 1][k][l] + cnt < lmin)
			{
				lmin = rec[n - 1][k][l] + cnt;
			}
		}

		return lmin;
	}
};

int main()
{
	Solution s;

	s.palindromePartition("leetcode", 8);
}