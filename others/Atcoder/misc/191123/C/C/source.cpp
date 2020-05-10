#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
	int n, m, k;
	vector<string> arr;
	vector<vector<int>> sol;
	vector<int> base;
	bool occ[301] = { 0, };
	int lastelem[301], lastocc = 0;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < m; i++)
	{
		base.push_back(0);
	}

	for (int i = 0; i < n; i++)
	{
		char input[301];

		scanf("%s", input);

		string str;

		str = input;

		arr.push_back(str);
		sol.push_back(base);

		for (int j = 0; j < m; j++)
		{
			if (str[j] == '#')
			{
				occ[i] = true;

				lastelem[i] = j;

				lastocc = i;
			}
		}
	}

	int lastrow = -1;
	int cnt = 1;

	for (int i = 0; i < n; i++)
	{
		int lastcol = -1;

		if (occ[i])
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == '#')
				{
					int ub;

					if (i == lastocc)
					{
						ub = n - 1;
					}

					else
					{
						ub = i;
					}

					for (int k = lastrow + 1; k <= ub; k++)
					{
						if (j == lastelem[i])
						{
							for (int l = lastcol + 1; l < m; l++)
							{
								sol[k][l] = cnt;
							}
						}

						else
						{
							for (int l = lastcol + 1; l <= j; l++)
							{
								sol[k][l] = cnt;
							}
						}
					}

					lastcol = j;

					cnt++;
				}
			}

			lastrow = i;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", sol[i][j]);
		}

		printf("\n");
	}

	return 0;
}
