#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	char input[100000];
	string str, sol;
	int i,j, n;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%s", input);

		str = input;

		n = str.size();

		sol.clear();

		if (n == 1)
		{
			printf("%s\n", str.c_str());

			continue;
		}

		if (str[0] != '1')
		{
			for (j = 1; j < n; j++)
			{
				if (str[j] != '9')
				{
					break;
				}
			}

			if (j == n)
			{
				printf("%c", str[0]);
			}

			else
			{
				printf("%c", str[0] - 1);
			}

			for (j = 1; j < n; j++)
			{
				printf("9");
			}

			printf("\n");

			continue;
		}

		else
		{
			sol.push_back('1');

			for (i = 1; i < n - 1; i++)
			{
				if (str[i] != '0')
				{
					for (j = i + 1; j < n; j++)
					{
						if (str[j] != '9')
						{
							break;
						}
					}

					if (j == n)
					{
						sol.push_back(str[i]);
					}

					else
					{
						sol.push_back(str[i] - 1);
					}

					for (j = i + 1; j < n; j++)
					{
						sol.push_back('9');
					}

					break;
				}

				sol.push_back(str[i]);
			}

			if (i == n - 1)
			{
				if (str[n - 1] == '0')
				{
					for (j = 0; j < n - 1; j++)
					{
						printf("9");
					}
				}

				else
				{
					sol.push_back(str[n - 1]);

					printf("%s", sol.c_str());
				}
			}

			else
			{
				printf("%s", sol.c_str());
			}
		}

		printf("\n");
	}

	return 0;
}