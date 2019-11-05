#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

int main()
{
	int n;
	int res;
	int i;

	scanf("%d", &n);

	printf("%d\n", n);

	for (i = 0; i < n; i++)
	{
		printf("1 ");
	}
/*
	if (n == 1)
	{
		printf("1\n1");
	}

	else if (!(n % 2))
	{
		printf("%d\n", n / 2);

		for (i = 0; i < n / 2; i++)
		{
			printf("2 ");
		}
	}

	else if (!(n % 3))
	{
		printf("%d\n", n / 3);

		for (i = 0; i < n / 3; i++)
		{
			printf("3 ");
		}
	}

	else if (!(n % 5))
	{
		printf("%d\n", n / 5);

		for (i = 0; i < n / 5; i++)
		{
			printf("5 ");
		}
	}

	else if (!(n % 7))
	{
		printf("%d\n", n / 7);

		for (i = 0; i < n / 7; i++)
		{
			printf("7 ");
		}
	}

	else
	{
		printf("%d\n", n / 2 + n % 2);

		for (i = 0; i < n / 2; i++)
		{
			printf("2 ");
		}

		if (n % 2)
		{
			printf("1");
		}
	}
*/
	return 0;
}