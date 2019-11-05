#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	int b, p, f;
	int h, c;
	int sol, add;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d %d %d", &b, &p, &f);
		scanf("%d %d", &h, &c);

		sol = 0;

		b /= 2;

		if (c > h)
		{
			add = b < f ? b : f;

			sol += add*c;

			b -= add;

			add = b < p ? b : p;

			sol += add*h;

			b -= add;
		}

		else
		{
			add = b < p ? b : p;

			sol += add*h;

			b -= add;

			add = b < f ? b : f;

			sol += add*c;

			b -= add;
		}

		printf("%d\n", sol);
	}

	return 0;
}