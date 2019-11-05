#include<cstdio>

using namespace std;

int main()
{
	int n;
	int i;

	scanf("%d", &n);

	printf("Christmas");

	for (i = 0; i < 25 - n; i++)
	{
		printf(" Eve");
	}

	printf("\n");

	return 0;
}