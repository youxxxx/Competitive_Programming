#include<cstdio>

using namespace std;

int main()
{
	int n;
	int look = 120;
	int i, j, k;
	bool taken[5] = { 0, };
	int dummy;

	freopen("input.txt", "w", stdout);

	printf("1 150\n");

	for (i = 0; i < 4; i++)
	{
		for (k = 0; k < look / (5 - i) - 1; k++)
		{
			printf("%c\n", (4 - i) + 'A');
		}

		for (j = i; j < 4; j++)
		{
			if (taken[j])
			{
				continue;
			}

			for (k = 0; k < look / (5 - i); k++)
			{
				printf("%c\n", j + 'A');
			}
		}

		taken[i] = true;
		
		look /= (5 - i);
	}

	printf("Y\n");

	return 0;
}