#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	int t, z;
	int n, m;
	int temp;
	int i, j;
	int x, y;
	int cnt;

	scanf("%d", &t);
	
	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &m);

		if (n == 1 || m == 1 || (n <= 3 && m <= 3) || (n == 2 && m == 4) || (n == 4 && m == 2))
		{
			printf("Case #%d: IMPOSSIBLE\n", z + 1);

			continue;
		}

		printf("Case #%d: POSSIBLE\n", z + 1);

		if (n == 2)
		{
			if (m == 5)
			{
				x = 2;
				y = 3;
				printf("%d %d\n", x, y);
				x = 1;
				y = 1;
				printf("%d %d\n", x, y);
				x = 2;
				y = 4;
				printf("%d %d\n", x, y);
				x = 1;
				y = 2;
				printf("%d %d\n", x, y);
				x = 2;
				y = 5;
				printf("%d %d\n", x, y);
				x = 1;
				y = 3;
				printf("%d %d\n", x, y);
				x = 2;
				y = 1;
				printf("%d %d\n", x, y);
				x = 1;
				y = 5;
				printf("%d %d\n", x, y);
				x = 2;
				y = 2;
				printf("%d %d\n", x, y);
				x = 1;
				y = 4;
				printf("%d %d\n", x, y);
			}

			else
			{
				if (!(m % 4 / 2))
				{
					x = 1;
					y = 1;

					while (y <= m)
					{
						printf("%d %d\n", x, y);

						x = 3 - x;

						y += 2;
					}

					x = 1;
					y = 2;

					while (y <= m)
					{
						printf("%d %d\n", x, y);

						x = 3 - x;

						y += 2;
					}

					x = 2;
					y = 1;

					while (y <= m)
					{
						printf("%d %d\n", x, y);

						x = 3 - x;

						y += 2;
					}

					x = 2;
					y = 2;

					while (y <= m)
					{
						printf("%d %d\n", x, y);

						x = 3 - x;

						y += 2;
					}
				}

				else
				{
					x = 1;
					y = 1;

					while (y <= m)
					{
						printf("%d %d\n", x, y);

						x = 3 - x;

						y += 2;
					}

					x = 2;
					y = 1;

					while (y <= m)
					{
						printf("%d %d\n", x, y);

						x = 3 - x;

						y += 2;
					}

					x = 1;
					y = 2;

					while (y <= m)
					{
						printf("%d %d\n", x, y);

						x = 3 - x;

						y += 2;
					}

					x = 2;
					y = 2;

					while (y <= m)
					{
						printf("%d %d\n", x, y);

						x = 3 - x;

						y += 2;
					}
				}
			}
		}

		else if (m == 2)
		{
			if (n == 5)
			{
				x = 2;
				y = 3;
				printf("%d %d\n", y, x);
				x = 1;
				y = 1;
				printf("%d %d\n", y, x);
				x = 2;
				y = 4;
				printf("%d %d\n", y, x);
				x = 1;
				y = 2;
				printf("%d %d\n", y, x);
				x = 2;
				y = 5;
				printf("%d %d\n", y, x);
				x = 1;
				y = 3;
				printf("%d %d\n", y, x);
				x = 2;
				y = 1;
				printf("%d %d\n", y, x);
				x = 1;
				y = 5;
				printf("%d %d\n", y, x);
				x = 2;
				y = 2;
				printf("%d %d\n", y, x);
				x = 1;
				y = 4;
				printf("%d %d\n", y, x);
			}

			else
			{
				temp = n;
				n = m;
				m = temp;

				if (!(m % 4 / 2))
				{
					x = 1;
					y = 1;

					while (y <= m)
					{
						printf("%d %d\n", y, x);

						x = 3 - x;

						y += 2;
					}

					x = 1;
					y = 2;

					while (y <= m)
					{
						printf("%d %d\n", y, x);

						x = 3 - x;

						y += 2;
					}

					x = 2;
					y = 1;

					while (y <= m)
					{
						printf("%d %d\n", y, x);

						x = 3 - x;

						y += 2;
					}

					x = 2;
					y = 2;

					while (y <= m)
					{
						printf("%d %d\n", y, x);

						x = 3 - x;

						y += 2;
					}
				}

				else
				{
					x = 1;
					y = 1;

					while (y <= m)
					{
						printf("%d %d\n", y, x);

						x = 3 - x;

						y += 2;
					}

					x = 2;
					y = 1;

					while (y <= m)
					{
						printf("%d %d\n", y, x);

						x = 3 - x;

						y += 2;
					}

					x = 1;
					y = 2;

					while (y <= m)
					{
						printf("%d %d\n", y, x);

						x = 3 - x;

						y += 2;
					}

					x = 2;
					y = 2;

					while (y <= m)
					{
						printf("%d %d\n", y, x);

						x = 3 - x;

						y += 2;
					}
				}
			}
		}

		else if (n == 3)
		{
			for (i = 0; i < m; i++)
			{
				x = 1;
				y = i + 1;
				printf("%d %d\n", x, y);
				x = 2;
				y = (i + 2) % m + 1;
				printf("%d %d\n", x, y);
				x = 3;
				y = i + 1;
				printf("%d %d\n", x, y);
			}
		}

		else if (m == 3)
		{
			temp = n;
			n = m;
			m = temp;

			for (i = 0; i < m; i++)
			{
				x = 1;
				y = i + 1;
				printf("%d %d\n", y, x);
				x = 2;
				y = (i + 2) % m + 1;
				printf("%d %d\n", y, x);
				x = 3;
				y = i + 1;
				printf("%d %d\n", y, x);
			}
		}

		else
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					x = (i + (j%2) * 2) % n + 1;
					y = j + 1;
					printf("%d %d\n", x, y);
				}
			}
		}
	}

	return 0;
}