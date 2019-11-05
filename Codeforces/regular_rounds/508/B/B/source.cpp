#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int i, j;

	scanf("%d", &n);

	if (n <= 2)
	{
		printf("No");
	}

	else if (n % 2)
	{
		printf("Yes\n");

		printf("%d", n - 1);

		for (i = 1; i <= n; i++)
		{
			if (i == n / 2 + 1)
			{
				continue;
			}

			printf(" %d", i);
		}

		printf("\n1 %d", n / 2 + 1);
	}

	else
	{
		printf("Yes\n");

		printf("%d", n - 2);

		for (i = 1; i <= n; i++)
		{
			if (i == n / 2 || i == n / 2 + 1)
			{
				continue;
			}

			printf(" %d", i);
		}

		printf("\n2 %d %d", n / 2, n / 2 + 1);
	}

	return 0;
}