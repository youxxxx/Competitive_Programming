#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	int sol[501][501];

	scanf("%d %d", &n, &m);

	if (n == 1 && m == 1)
	{
		printf("0\n");

		return 0;
	}

	if (n == 1)
	{
		for (int i = 1; i <= m; i++)
		{
			printf("%d ", i + 1);
		}

		return 0;
	}

	if (m == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			printf("%d\n", i + 1);
		}

		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", i*(j + n + 1));
		}

		printf("\n");
	}

	return 0;
}