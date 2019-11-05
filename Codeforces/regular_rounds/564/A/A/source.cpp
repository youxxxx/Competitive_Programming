#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int x, y, z;
	int ub, lb;

	scanf("%d %d %d", &x, &y, &z);

	lb = x - y - z;
	ub = x - y + z;

	if (lb > 0)
	{
		printf("+\n");
	}

	else if (ub < 0)
	{
		printf("-\n");
	}

	else if (lb == 0 && ub == 0)
	{
		printf("0\n");
	}

	else
	{
		printf("?\n");
	}

	return 0;
}