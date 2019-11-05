#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	int n;
	int a, b, c;
	int sub;
	int lmin;
	int sol;
	int cand1, cand2;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d %d %d", &a, &b, &c);

		lmin = a < b ? a : b;

		sub = a - lmin;
		c += sub;
		sub = b - lmin;
		c += sub;

		if (c >= lmin)
		{
			sol = lmin;
		}

		else
		{
			cand1 = c + (lmin - c) / 3 * 2;
			cand2 = lmin - ((lmin - c) / 3 + 1);

			sol = cand1 > cand2 ? cand1 : cand2;
		}

		printf("%d\n", sol);
	}

	return 0;
}