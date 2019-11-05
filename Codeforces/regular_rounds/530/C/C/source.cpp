#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	char input[1000];
	string str;
	int i, j, n, m;
	int canes = 0, flakes = 0, tot;
	int left;

	scanf("%s", input);
	scanf("%d", &m);

	str = input;

	n = str.size();

	for (i = 0; i < n; i++)
	{
		if (str[i] == '?')
		{
			canes++;
		}

		else if (str[i] == '*')
		{
			flakes++;
		}
	}

	tot = n - (canes + flakes);

	if (m < tot - (canes + flakes) || m > tot && flakes == 0)
	{
		printf("Impossible\n");
	}

	else
	{
		if (m == tot)
		{
			for (i = 0; i < n; i++)
			{
				if (str[i] != '?'&&str[i]!='*')
				{
					printf("%c", str[i]);
				}
			}
		}

		else
		{
			left = abs(m - tot);

			if (m < tot)
			{
				for (i = 0; i < n; i++)
				{
					if (i < n - 1 && str[i + 1] == '?' || str[i + 1] == '*')
					{
						if (left > 0)
						{
							left--;
						}

						else
						{
							printf("%c", str[i]);
						}
					}

					else if (str[i] != '?'&&str[i] != '*')
					{
						printf("%c", str[i]);
					}
				}
			}

			else
			{
				for (i = 0; i < n; i++)
				{
					if (i < n - 1 && left > 0 && str[i + 1] == '*')
					{
						for (j = 0; j < left + 1; j++)
						{
							printf("%c", str[i]);
						}

						left = 0;
					}

					else if(str[i] != '?'&&str[i] != '*')
					{
						printf("%c", str[i]);
					}
				}
			}
		}
	}

	return 0;
}