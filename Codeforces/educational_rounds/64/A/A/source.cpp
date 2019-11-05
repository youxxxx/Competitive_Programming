#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int i;
	int input, prev, prev2 = -1;
	int cnt = 0;
	bool inf = false;

	scanf("%d", &n);

	scanf("%d", &input);

	prev = input;

	for (i = 1; i < n; i++)
	{
		scanf("%d", &input);

		if (prev == 1)
		{
			if (input == 2)
			{
				if (prev2 == 3)
				{
					cnt += 2;
				}

				else
				{
					cnt += 3;
				}
			}

			else
			{
				cnt += 4;
			}
		}

		else if (prev == 2)
		{
			if (input == 1)
			{
				cnt += 3;
			}

			else
			{
				inf = true;

				break;
			}
		}

		else
		{
			if (input == 1)
			{
				cnt += 4;
			}

			else
			{
				inf = true;

				break;
			}
		}

		prev2 = prev;
		prev = input;
	}

	if (inf)
	{
		printf("Infinite\n");

		return 0;
	}

	printf("Finite\n%d\n", cnt);

	return 0;
}