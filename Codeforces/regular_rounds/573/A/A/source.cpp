#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int cat[4] = { 0,3,1,2 };
	int i;
	int sol = 0, lmax = -1;

	scanf("%d", &n);

	for (i = 0; i < 3; i++)
	{
		if (cat[(n + i) % 4] > lmax)
		{
			lmax = cat[(n + i) % 4];

			sol = i;
		}
	}

	printf("%d %c\n", sol, 3 - cat[(n + sol) % 4] + 'A');

	return 0;
}