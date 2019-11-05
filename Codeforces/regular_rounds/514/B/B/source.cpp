#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<string> sign;
	string str;
	char input[1001];
	int r[8] = { -1,-1,-1,0,0,1,1,1 };
	int c[8] = { -1,0,1,-1,1,-1,0,1 };
	int n, m;
	int i, j, k;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		str = input;

		sign.push_back(input);
	}

	for (i = 1; i < n - 1; i++)
	{
		for (j = 1; j < m - 1; j++)
		{
			for (k = 0; k < 8; k++)
			{
				if (sign[i + r[k]][j + c[k]] == '.')
				{
					break;
				}
			}

			if (k == 8)
			{
				for (k = 0; k < 8; k++)
				{
					sign[i + r[k]][j + c[k]] = ' ';
				}
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (sign[i][j] == '#')
			{
				printf("NO");

				return 0;
			}
		}
	}

	printf("YES");

	return 0;
}