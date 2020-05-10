#include<cstdio>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	int n, m;
	int i, j;
	int la, lb, ua, ub;
	int num;

	scanf("%d", &n);

	m = n / 2;

	num = 2 * m*(m - 1) + (n - 1)*(n % 2);

	printf("%d\n", num);

	for (i = 1; i < m; i++)
	{
		la = i;
		ua = m * 2 + 1 - i;

		for (j = i + 1; j <= m; j++)
		{
			lb = j;
			ub = m * 2 + 1 - j;

			printf("%d %d\n%d %d\n%d %d\n%d %d\n", la, lb, la, ub, ua, lb, ua, ub);
		}
	}

	if (n % 2)
	{
		for (i = 1; i < n; i++)
		{
			printf("%d %d\n", i, n);
		}
	}

	return 0;
}