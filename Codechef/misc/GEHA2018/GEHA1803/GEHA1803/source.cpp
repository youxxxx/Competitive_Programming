#include<cstdio>

int main()
{
	int n, q;
	int i, j;
	int l, r, x, y;
	int input;
	int cnt;
	int *arr;

	scanf("%d %d", &n, &q);

	arr = new int[n + 1];

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &l, &r, &x, &y);

		cnt = 0;

		for (j = l; j <= r; j++)
		{
			cnt += ((arr[j] ^ x) >= y);
		}

		printf("%d\n", cnt);
	}

	return 0;
}