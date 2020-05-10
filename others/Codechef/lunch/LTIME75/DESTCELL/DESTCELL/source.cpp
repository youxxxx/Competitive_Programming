#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	int n, m;
	int r;
	int mlt;
	int i, j;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d %d", &n, &m);

		printf("%d", n*m);

		for (i = 2; i < n*m; i++)
		{
			if (n%i&&m%i)
			{
				printf(" %d", 1 + (n*m - 1) / i);
			}

			else if(!(n%i)&&!(m%i))
			{
				printf(" %d", (n*m / i) * 2 - (n*m / (i*i)));
			}

			else if (!(n%i))
			{
				r = m%i;

				for (j = 2; j <= n; j++)
				{
					if (!(r*j%n))
					{
						mlt = j;

						break;
					}
				}

				printf(" %d", 1 + ((n*m - 1) / i) * 2 - ((m - 1) / mlt));
			}

			else
			{
				r = n%i;

				for (j = 2; j <= m; j++)
				{
					if (!(r*j%m))
					{ 
						mlt = j;

						break;
					}
				}

				printf(" %d", 1 + ((n*m - 1) / i) * 2 - ((n - 1) / mlt));
			}
		}

		printf(" 1\n");
	}

	return 0;
}