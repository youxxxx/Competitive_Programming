#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	int t, z;
	int n, q;
	int i, j;
	char temp;
	char input;
	vector<vector<char>> arr;
	vector<char> emp;
	int min;
	int cnt;
	int x, y;
	int **val;

	val = new int*[1001];

	for (i = 1; i <= 1000; i++)
	{
		val[i] = new int[1001];
	}

	emp.push_back(0);

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		cnt = 1;

		scanf("%d %d", &n, &q);

		arr.push_back(emp);

		for (i = 1; i <= n; i++)
		{
			arr.push_back(emp);

			for (j = 1; j <= n; j++)
			{
				scanf("%c %c", &temp, &input);

				arr[i].push_back(input);
			}
		}

		val[1][1] = !!(arr[1][1] - 'a');

		for (i = 2; i <= n; i++)
		{
			val[i][1] = val[i - 1][1] + !!(arr[i][1] - 'a');

			cnt++;

			for (j = 2; j <= i - 1; j++)
			{
				min = val[i - j][j];

				if (val[i - j + 1][j - 1] < min)
				{
					min = val[i - j + 1][j - 1];
				}

				val[i - j + 1][j] = min + !!(arr[i - j + 1][j] - 'a');

				cnt++;
			}

			val[1][i] = val[1][i - 1] + !!(arr[1][i] - 'a');

			cnt++;
		}

		for (i = 1; i <= n - 1; i++)
		{
			for (j = i + 1; j <= n; j++)
			{
				min = val[n + i - j][j];

				if (val[n + i - j + 1][j - 1] < min)
				{
					min = val[n + i - j + 1][j - 1];
				}

				val[n + i - j + 1][j] = min + !!(arr[n + i - j + 1][j] - 'a');

				cnt++;
			}
		}

		for (i = 0; i < q; i++)
		{
			scanf("%d %d", &x, &y);

			printf("%d\n", val[x][y]);
		}

		arr.clear();
	}

	return 0;
}