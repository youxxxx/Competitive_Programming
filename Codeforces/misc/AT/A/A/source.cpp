#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int n, m;
	char input[116];
	int i, j, ptr, sol;
	bool found = false;
	string str[115];

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		str[i] = input;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (str[i][j] == 'B')
			{
				ptr = j;

				while (++ptr < m&&str[i][ptr] == 'B');

				found = true;

				break;
			}
		}

		if (found)
		{
			break;
		}
	}
	
	sol = (ptr - j - 1) / 2;

	printf("%d %d", i + sol + 1, j + sol + 1);

	return 0;
}