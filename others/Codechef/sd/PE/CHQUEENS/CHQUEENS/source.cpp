#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int t, z;
	int n, m, x, y;
	int i, j, k;
	int sum, psum[8], sub;
	int min;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d %d %d", &n, &m, &x, &y);

		sum = 0;

		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (i == x&&j == y)
				{
					continue;
				}

				psum[0] = i - 1;
				psum[1] = n - i;
				psum[2] = j - 1;
				psum[3] = m - j;

				psum[4] = psum[0] < psum[2] ? psum[0] : psum[2];
				psum[5] = psum[0] < psum[3] ? psum[0] : psum[3];
				psum[6] = psum[1] < psum[2] ? psum[1] : psum[2];
				psum[7] = psum[1] < psum[3] ? psum[1] : psum[3];

				if (i == x)
				{
					if (y<j)
					{
						sub = y - 1;
					}

					else
					{
						sub = m - y;
					}
				}

				else if (j == y)
				{
					if (x<i)
					{
						sub = x - 1;
					}

					else
					{
						sub = n - x;
					}
				}
				
				else if (i - x == j - y)
				{
					if (i - x > 0)
					{
						sub = psum[4] - (i - x);
					}

					else
					{
						sub = psum[7] - (x - i);
					}
				}

				else if (i - x == j - y)
				{
					if (i - x > 0)
					{
						sub = psum[4] - (i - x);
					}

					else
					{
						sub = psum[7] - (x - i);
					}
				}

				else if (i - x == -(j - y))
				{
					if (i - x > 0)
					{
						sub = psum[5] - (i - x);
					}

					else
					{
						sub = psum[6] - (x - i);
					}
				}

				else
				{
					sub = -1;
				}

				sum += n*m - 1 + sub;

				for (k = 0; k < 8; k++)
				{
					sum -= psum[k];
				}
			}
		}

		printf("%d\n", sum); 
	}

	return 0;
}