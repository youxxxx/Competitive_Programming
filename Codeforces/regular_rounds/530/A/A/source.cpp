#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

int main()
{
	int w, h;
	int u1, d1, u2, d2;
	int temp;
	int i;
	int sol;

	scanf("%d %d", &w, &h);
	scanf("%d %d", &u1, &d1);
	scanf("%d %d", &u2, &d2);

	if (d2 > d1)
	{
		temp = u1;
		u1 = u2;
		u2 = temp;

		temp = d1;
		d1 = d2;
		d2 = temp;
	}

	sol = w;

	sol += (h + d1)*(h - d1 + 1) / 2;
	sol -= u1;

	if (sol < 0)
	{
		sol = 0;
	}

	sol += (d1 + d2 - 1)*(d1 - d2) / 2;
	sol -= u2;

	if (sol < 0)
	{
		sol = 0;
	}

	sol += d2*(d2 - 1) / 2;

	printf("%d\n", sol);

	return 0;
}