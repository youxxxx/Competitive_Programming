#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	int a, b, c;
	int i;
	int sol, cand;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		sol = 0;

		scanf("%d %d %d", &a, &b, &c);

		for (i = 0; i <= a && i * 2 <= b; i++)
		{
			cand = i * 3 + ((b - 2 * i) < c / 2 ? (b - 2 * i) : c / 2) * 3;

			if (cand > sol)
			{
				sol = cand;
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}