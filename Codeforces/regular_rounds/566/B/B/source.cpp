#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

#define MOD 1000000007;

using namespace std;

int main()
{
	int n, m;
	int row[500] = { 0, }, col[500] = { 0, };
	int cr, cc;
	char input[1000];
	string str;
	int i, j;
	vector<string> arr;
	bool start, end;
	bool one, none;
	bool valid = true;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		str = input;

		arr.push_back(input);

		start = end = false;

		for (j = 0; j < m; j++)
		{
			if (arr[i][j] == '*')
			{
				if (!start)
				{
					start = true;
				}

				else if (end)
				{
					valid = false;
				}

				row[i]++;
			}

			else
			{
				if (start && !end)
				{
					end = true;
				}
			}
		}
	}

	if (!valid)
	{
		printf("NO\n");

		return 0;
	}

	for (i = 0; i < m; i++)
	{
		start = end = false;

		for (j = 0; j < n; j++)
		{
			if (arr[j][i] == '*')
			{
				if (!start)
				{
					start = true;
				}

				else if (end)
				{
					printf("NO\n");

					return 0;
				}

				col[i]++;
			}

			else
			{
				if (start && !end)
				{
					end = true;
				}
			}
		}
	}

	end = false;
	one = none = false;

	for (i = 0; i < n; i++)
	{
		if (row[i] != 0)
		{
			if (row[i] == 1)
			{
				one = true;

				if (none)
				{
					end = true;
				}
			}

			else
			{
				if (!one || none || end)
				{
					printf("NO\n");

					return 0;
				}

				cr = i;

				none = true;
			}
		}
	}

	if (!end)
	{
		printf("NO\n");

		return 0;
	}

	end = false;
	one = none = false;

	for (i = 0; i < m; i++)
	{
		if (col[i] != 0)
		{
			if (col[i] == 1)
			{
				one = true;

				if (none)
				{
					end = true;
				}
			}

			else
			{
				if (!one || none || end)
				{
					printf("NO\n");

					return 0;
				}

				cc = i;

				none = true;
			}
		}
	}

	if (!end)
	{
		printf("NO\n");

		return 0;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (arr[i][j] == '*'&&i != cr&&j != cc)
			{
				printf("NO\n");

				return 0;
			}
		}
	}

	if (arr[cr][cc] == '.')
	{
		printf("NO\n");

		return 0;
	}

	if (	cr > 0 && arr[cr - 1][cc] == '.'
		|| cr < n - 1 && arr[cr + 1][cc] == '.'
		|| cc > 0 && arr[cr][cc - 1] == '.'
		|| cc < m - 1 && arr[cr][cc + 1] == '.')
	{
		printf("NO\n");

		return 0;
	}

	end = false;

	for (i = cr - 1; i >= 0; i--)
	{
		if (arr[i][cc] == '.')
		{
			end = true;
		}

		else if (end)
		{
			printf("NO\n");

			return 0;
		}
	}

	end = false;

	for (i = cr + 1; i < n; i++)
	{
		if (arr[i][cc] == '.')
		{
			end = true;
		}

		else if (end)
		{
			printf("NO\n");

			return 0;
		}
	}

	end = false;

	for (i = cc - 1; i >= 0; i--)
	{
		if (arr[cr][i] == '.')
		{
			end = true;
		}

		else if (end)
		{
			printf("NO\n");

			return 0;
		}
	}

	end = false;

	for (i = cc + 1; i < m; i++)
	{
		if (arr[cr][i] == '.')
		{
			end = true;
		}

		else if (end)
		{
			printf("NO\n");

			return 0;
		}
	}

	printf("YES\n");

	return 0;
}