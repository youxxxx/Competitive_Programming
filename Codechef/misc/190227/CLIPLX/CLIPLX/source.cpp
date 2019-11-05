#include<cstdio>

using namespace std;

int main()
{
	int t, x, y;
	int z;
	int sol;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &x, &y);

		sol = x - y;

		if (sol < 0)
		{
			sol = 0;
		}

		printf("%d\n", sol);
	}

	return 0;
}