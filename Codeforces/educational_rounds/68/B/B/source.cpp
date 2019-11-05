#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t, tc;
	int n, m;
	char input[100000];
	vector<string> arr;
	string str;
	int row[50000], col[50000];
	int i, j;
	int lmin;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &tc);

	for (t = 0; t < tc; t++)
	{
		scanf("%d %d", &n, &m);

		lmin = 999999;

		arr.clear();

		for (i = 0; i < n; i++)
		{
			row[i] = m;
		}

		for (i = 0; i < m; i++)
		{
			col[i] = n;
		}

		for (i = 0; i < n; i++)
		{
			scanf("%s", input);

			str = input;

			for (j = 0; j < m; j++)
			{
				if (str[j] == '*')
				{
					row[i]--;

					col[j]--;
				}
			}

			arr.push_back(str);
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (row[i] + col[j] - (arr[i][j] == '.') < lmin)
				{
					lmin = row[i] + col[j] - (arr[i][j] == '.');
				}
			}
		}

		printf("%d\n", lmin);
	}

	return 0;
}