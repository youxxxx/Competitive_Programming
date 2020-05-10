#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
	int x, y;
	int sol = 0;
	int prize[4] = { 0,300000,200000,100000 };

	scanf("%d %d", &x, &y);

	if (x <= 3)
	{
		sol += prize[x];
	}

	if (y <= 3)
	{
		sol += prize[y];
	}

	if (x == 1 && y == 1)
	{
		sol += 400000;
	}

	printf("%d\n", sol);

	return 0;
}
