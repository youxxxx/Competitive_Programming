#include<cstdio>

int main()
{
	int max = 0, sum = 0;
	int input;
	int i, n;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if (input > max)
		{
			max = input;
		}

		sum += input;
	}

	if (max >= sum - max)
	{
		printf("No\n");
	}

	else
	{
		printf("Yes\n");
	}

	return 0;
}