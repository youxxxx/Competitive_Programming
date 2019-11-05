#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	int n, m;
	int i;
	int q;

	scanf("%d %d", &n, &m);

	q = n / 4;

	for (i = 0; i < q; i++)
	{
		printf("4");
	}

	printf("5\n");

	for (i = 0; i < q + 1; i++)
	{
		printf("5");
	}

	return 0;
}