#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int i;
	long long a, b, c;
	long long base, sol;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld %lld %lld", &a, &b, &c);

		if (a <= b)
		{
			c -= b - a + 1;

			if (c < 0)
			{
				sol = 0;
			}

			else
			{
				sol = c / 2 + 1;
			}
		}

		else
		{
			if (b + c < a)
			{
				sol = c + 1;
			}

			else
			{
				base = (a - 1 - b);

				base += (c - base) / 2;

				sol = base + 1;
			}
		}


		printf("%lld\n", sol);
	}

	return 0;
}