#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

int main()
{
	int n, a, b;
	int min, max;

	scanf("%d %d %d", &n, &a, &b);

	max = a < b ? a : b;

	min = (a + b - n) > 0 ? a + b - n : 0;

	printf("%d %d\n", max, min);

	return 0;
}