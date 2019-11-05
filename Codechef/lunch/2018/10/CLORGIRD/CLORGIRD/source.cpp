#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int t, z;
	int n, m;
	int i, j;
	vector<string> grid;
	string str;
	char input[1001];

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &m);

		for (i = 0; i < n; i++)
		{
			scanf("%s", input);

			str = input;

			grid.push_back(str);
		}

		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < m - 1; j++)
			{
				if (grid[i][j] != '#'&&grid[i + 1][j] != '#'&&grid[i][j + 1] != '#'&&grid[i + 1][j + 1] != '#')
				{
					grid[i][j] = ' ';
					grid[i+1][j] = ' ';
					grid[i][j+1] = ' ';
					grid[i+1][j+1] = ' ';
				}
			}
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (grid[i][j] == '.')
				{
					break;
				}
			}

			if (j != m)
			{
				break;
			}
		}

		if (i == n)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}

		grid.clear();
	}

	return 0;
}