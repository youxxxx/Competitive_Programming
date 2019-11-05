#include<cstdio>

using namespace std;

int main()
{
	int y, b, r;
	int min;

	scanf("%d %d %d", &y, &b, &r);

	min = r;

	if (b < min - 1)
	{
		min = b + 1;
	}
	if (y < min - 2)
	{
		min = y + 2;
	}

	printf("%d\n", min * 3 - 3);

	return 0;
}