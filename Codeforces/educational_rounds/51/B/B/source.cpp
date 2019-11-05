#include<cstdio>

using namespace std;

int main()
{
	long long a, b;
	long long i;

	scanf("%I64d %I64d", &a, &b);

	printf("YES\n");

	for (i = a; i < b; i += 2)
	{
		printf("%I64d %I64d\n", i, i + 1);
	}

	return 0;
}