#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	int food[7] = { 0,1,2,0,2,1,0 };
	int divd[3] = { 3,2,2 };
	int x[3];
	int temp[3];
	int i, j;
	int input;
	int lmin = 999999999, lmax = 0;
	int sol;

	for (i = 0; i < 3; i++)
	{
		scanf("%d", &x[i]);
	}

	for (i = 0; i < 3; i++)
	{
		if (x[i] / divd[i] < lmin)
		{
			lmin = x[i] / divd[i];
		}
	}

	sol = lmin * 7;

	for (i = 0; i < 3; i++)
	{
		x[i] -= lmin*divd[i];
	}

	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 3; j++)
		{
			temp[j] = x[j];
		}

		for (j = 0; j < 7; j++)
		{
			if (!(temp[food[(i + j) % 7]]--))
			{
				break;
			}
		}

		if (j > lmax)
		{
			lmax = j;
		}
	}

	sol += lmax;

	printf("%d\n", sol);

	return 0;
}