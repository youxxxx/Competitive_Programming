#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	int n;
	char input[200001];
	string str, sol;
	int i, j;
	int bcur, acur;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d", &n);

		scanf("%s", input);

		str = input;

		for (i = 0; i < n; i++)
		{
			str[i] -= '0';
		}

		for (i = 0; i <= 10; i++)
		{
			sol.clear();

			acur = 0;
			bcur = i;

			for (j = 0; j < n; j++)
			{
				if (str[j] < bcur)
				{
					if (str[j] < acur)
					{
						break;
					}

					acur = str[j];

					sol.push_back('1');
				}

				else
				{
					bcur = str[j];

					sol.push_back('2');
				}
			}

			if (j == n && acur <= i)
			{
				break;
			}
		}

		if (i == 11)
		{
			printf("-\n");
		}

		else
		{
			printf("%s\n", sol.c_str());
		}
	}

	return 0;
}