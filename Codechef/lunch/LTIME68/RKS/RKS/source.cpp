#include<cstdio>

using namespace std;

int main()
{
	bool *x, *y;
	int n, k;
	int t, z;
	int i, j;
	int ptr1, ptr2;
	int row, col;

	scanf("%d", &t);

	x = new bool[1000001];
	y = new bool[1000001];

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &k);

		for (i = 1; i <= n; i++)
		{
			x[i] = y[i] = false;
		}

		for (i = 0; i < k; i++)
		{
			scanf("%d %d", &row, &col);

			x[row] = true;
			y[col] = true;
		}

		printf("%d", n - k);

		row = col = 0;

		for (i = 0; i < n - k; i++)
		{
			while (x[++row]);
			while (y[++col]);

			printf(" %d %d", row, col);
		}

		printf("\n");
	}

	return 0;
}