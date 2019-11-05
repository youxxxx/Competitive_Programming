#include<cstdio>

using namespace std;

int main()
{
	int n;
	long long int a, b, max = 0;
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d %I64d", &a, &b);

		if (a + b > max)
		{
			max = a + b;
		}
	}

	printf("%I64d", max);

	return 0;
}