#define _USE_MATH_DEFINES

#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	int i, j;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n / 2; i++)
	{
		for (j = 1; j <= m; j++)
		{
			printf("%d %d\n", i, j);
			printf("%d %d\n", n - i + 1, m - j + 1);
		}
	}

	if (n % 2)
	{
		for (j = 1; j <= m / 2; j++)
		{
			printf("%d %d\n", (n + 1) / 2, j);
			printf("%d %d\n", (n + 1) / 2, m - j + 1);
		}

		if (m % 2)
		{
			printf("%d %d\n", (n + 1) / 2, (m + 1) / 2);
		}
	}

	return 0;
}