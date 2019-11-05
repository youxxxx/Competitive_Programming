#include<cstdio>

int main()
{
	long long n, x, y;
	long long max1, max2;

	scanf("%I64d %I64d %I64d", &n, &x, &y);

	max1 = x > y ? x : y;
	max1--;
	max2 = n - x > n - y ? n - x : n - y;

	if (max2 < max1)
	{
		printf("Black\n");
	}

	else
	{
		printf("White\n");
	}

	return 0;
}