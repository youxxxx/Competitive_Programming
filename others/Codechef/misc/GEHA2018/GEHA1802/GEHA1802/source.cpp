#include<cstdio>

using namespace std;

int main()
{
	int t, z;
	int n, m;
	int *arr;
	int i, j;
	int input;
	int max;
	int maxblock;
	int start;
	bool valid;

	arr = new int[1000001];

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &m);

		for (i = 0; i <= n; i++)
		{
			arr[i] = 0;
		}

		for (i = 0; i < m; i++)
		{
			scanf("%d", &input);

			arr[input]++;
		}

		max = 0;

		for (i = 0; i <= n; i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}

		maxblock = 0;

		for (i = 1; i <= max; i++)
		{
			start = -1;

			while (++start < n&&arr[start] < i);

			valid = true;

			for (j = start + 1; j <= n; j++)
			{
				if (arr[j] < i)
				{
					if (valid)
					{
						if ((j - start)*i > maxblock)
						{
							maxblock = (j - start)*i;
						}
					}

					valid = false;
				}

				if (!valid&&arr[j] >= i)
				{
					start = j;

					valid = true;
				}
			}

			if (valid)
			{
				if ((j - start)*i > maxblock)
				{
					maxblock = (j - start)*i;
				}
			}
		}

		printf("%d\n", maxblock);
	}

	return 0;
}