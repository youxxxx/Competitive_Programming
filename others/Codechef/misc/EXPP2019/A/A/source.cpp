#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>

using namespace std;

int main()
{
	int tc, cases;
	int n;
	int lmin;
	int i;
	int input;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d", &n);

		lmin = 999999999;

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			if (input < lmin)
			{
				lmin = input;
			}
		}

		printf("%d\n", lmin);
	}

	return 0;
}