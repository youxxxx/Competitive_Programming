#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		int lmin = 30001;
		int num[3];

		for (int i = 1; i <= 10000; i++)
		{
			int adiff;

			adiff = abs(a - i);

			if (adiff > lmin)
			{
				continue;
			}

			for (int j = i; j <= 20000; j += i)
			{
				int bdiff, cdiff;
				int cand;

				bdiff = abs(b - j);

				int q;

				q = c / j;

				if (j > c)
				{
					cdiff = j - c;

					cand = (q + 1)*j;
				}

				else
				{
					if (c%j < j - (c%j))
					{
						cdiff = c%j;

						cand = q*j;
					}

					else
					{
						cdiff = j - (c%j);

						cand = (q + 1)*j;
					}
				}

				int sol;

				sol = adiff + bdiff + cdiff;

				if (sol < lmin)
				{
					lmin = sol;

					num[0] = i;
					num[1] = j;
					num[2] = cand;
				}
			}
		}

		printf("%d\n%d %d %d\n", lmin, num[0], num[1], num[2]);
	}

	return 0;
}