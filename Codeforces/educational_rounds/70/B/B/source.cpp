#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	char input[2000001];
	string str;
	int lmin[10][10][10];
	int i, j, k, l, m;
	int n;
	int cand;
	bool found;
	int val;

	scanf("%s", input);
	str = input;
	n = str.size();

	for (i = 0; i < 10; i++)
	{
		lmin[i][0][0] = -1;

		for (j = 0; j < 10; j++)
		{
			for (k = 0; k < 10; k++)
			{
				if (j == 0 && k == 0)
				{
					continue;
				}

				lmin[i][j][k] = -1;

				for (l = 1; l <= 20; l++)
				{
					found = false;

					for (m = 0 > l - 10 ? 0 : l - 10; m <= (l < 10 ? l : 10); m++)
					{
						cand = (j*m + k*(l - m));

						if (cand == 0)
						{
							continue;
						}

						cand %= 10;

						if (cand == i)
						{
							found = true;

							break;
						}
					}

					if (found)
					{
						lmin[i][j][k] = l;

						break;
					}
				}
			}
		}
	}

	for (i = 0; i < 10; i++)
	{
		lmin[0][0][i] = lmin[0][i][0] = 1;
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			val = 0;

			for (k = 1; k < n; k++)
			{
				if (lmin[(10 + str[k] - str[k - 1]) % 10][i][j] == -1)
				{
					break;
				}

				val += lmin[(10 + str[k] - str[k - 1]) % 10][i][j] - 1;
			}
			
			if (k != n)
			{
				printf("-1 ");
			}

			else
			{
				printf("%d ", val);
			}
		}

		printf("\n");
	}

	return 0;
}