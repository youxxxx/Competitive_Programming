#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	int n, h, a, b, k;
	int ta, fa, tb, fb;
	int i;
	int mina, minb;

	scanf("%d %d %d %d %d", &n, &h, &a, &b, &k);

	for (i = 0; i < k; i++)
	{
		scanf("%d %d %d %d", &ta, &fa, &tb, &fb);

		if (ta == tb)
		{
			printf("%d\n", abs(fb - fa));
		}

		else
		{
			if (fa >= a&&fa <= b)
			{
				mina = 0;
			}

			else
			{
				if (abs(fa - b) < abs(fa - a))
				{
					mina = abs(fa - b);

					fa = b;
				}

				else
				{
					mina = abs(fa - a);

					fa = a;
				}
			}

			printf("%d\n", mina + abs(tb - ta) + abs(fb - fa));
		}
	}

	return 0;
}