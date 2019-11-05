#include<cstdio>

using namespace std;

int main()
{
	int n, c, i;
	scanf("%d", &n);

	c = 1;
	while (1)
	{
		if (n > 3)
		{
			for (i = 1; i <= n - n / 2; i++)
				printf("%d ", c);
			n = n >> 1;
			c = c << 1;
			continue;
		}

		if (n == 1)
		{
			printf("%d", c);
		}

		else if (n == 2)
		{
			printf("%d %d", c, c<<1);
		}

		else if (n == 3)
		{
			printf("%d %d %d", c, c, c * 3);
		}

		break;
	}

	return 0;
}