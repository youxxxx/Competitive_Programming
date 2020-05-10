#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;
		int arr[1000][1000];
		int lmax[1000][1000];

		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		string windows;

		for (int j = 0; j < m; j++)
		{
			lmax[0][j] = arr[0][j];

			windows.push_back('1');
		}

		printf("%s\n", windows.c_str());

		for (int i = 1; i < n; i++)
		{
			string windows;

			for (int j = 0; j < m; j++)
			{
				int curmax = 0;

				if (j > 0 && lmax[i - 1][j - 1] > curmax)
				{
					curmax = lmax[i - 1][j - 1];
				}

				if (lmax[i - 1][j] > curmax)
				{
					curmax = lmax[i - 1][j];
				}

				if (j < m - 1 && lmax[i - 1][j + 1] > curmax)
				{
					curmax = lmax[i - 1][j + 1];
				}

				if (curmax > arr[i][j])
				{
					windows.push_back('0');

					lmax[i][j] = curmax;
				}

				else
				{
					windows.push_back('1');

					lmax[i][j] = arr[i][j];
				}
			}

			printf("%s\n", windows.c_str());
		}
	}

	return 0;
}