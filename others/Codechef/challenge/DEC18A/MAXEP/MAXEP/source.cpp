#include<cstdio>

using namespace std;

int main()
{
	int n, c;
	int lb, ub;
	int i;
	int res;
	bool broken = false;

	scanf("%d %d", &n, &c);

	if (n <= 4)
	{
		for (i = 1; i < n; i++)
		{
			printf("1 %d\n", i);
			fflush(stdout);

			scanf("%d", &res);

			if (res == 1)
			{
				printf("2\n");
				fflush(stdout);

				printf("3 %d\n", i);

				return 0;
			}
		}

		printf("3 %d\n", n);
	}

	if (n <= 600)
	{
		printf("1 %d\n", n / 2);
		fflush(stdout);

		scanf("%d", &res);

		if (res == 1)
		{
			printf("2\n");
			fflush(stdout);

			lb = 1;

			ub = n / 2;
		}
			
		else
		{
			lb = n / 2 + 1;
			ub = n;
		}

		for (i = lb; i < ub; i++)
		{
			printf("1 %d\n", i);
			fflush(stdout);

			scanf("%d", &res);

			if (res == 1)
			{
				printf("2\n");
				fflush(stdout);

				printf("3 %d\n", i);

				return 0;
			}
		}

		printf("3 %d\n", ub);

		return 0;
	}

	for (i = 1; i <= (n - 1) / 600; i++)
	{
		printf("1 %d\n", i * 600);
		fflush(stdout);

		scanf("%d", &res);

		if (res == 1)
		{
			printf("2\n");
			fflush(stdout);

			broken = true;

			break;
		}
	}

	if (!broken)
	{
		lb = (i - 1) * 600 + 1;

		ub = n;
	}

	else
	{
		lb = (i - 1) * 600 + 1;

		ub = i * 600;
	}
	
	if (ub - lb <= 4)
	{
		for (i = lb; i < n; i++)
		{
			printf("1 %d\n", i);
			fflush(stdout);

			scanf("%d", &res);

			if (res == 1)
			{
				printf("2\n");
				fflush(stdout);

				printf("3 %d\n", i);

				return 0;
			}
		}

		printf("3 %d\n", n);

		return 0;
	}

	printf("1 %d\n", (lb + ub - 1) / 2);
	fflush(stdout);

	scanf("%d", &res);

	if (res == 1)
	{
		printf("2\n");
		fflush(stdout);

		ub = (lb + ub - 1) / 2;
	}

	else
	{
		lb = (lb + ub - 1) / 2 + 1;
	}

	for (i = lb; i < ub; i++)
	{
		printf("1 %d\n", i);
		fflush(stdout);

		scanf("%d", &res);

		if (res == 1)
		{
			printf("2\n");
			fflush(stdout);

			printf("3 %d\n", i);

			return 0;
		}
	}

	printf("3 %d\n", ub);

	return 0;	
}