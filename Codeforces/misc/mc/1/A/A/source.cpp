#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	int x, y, z, t1, t2, t3;

	scanf("%d %d %d %d %d %d", &x, &y, &z, &t1, &t2, &t3);

	if ((abs(x - y) + abs(x - z))*t2 + t3 * 3 <= abs(x - y)*t1)
	{
		printf("YES");
	}

	else
	{
		printf("NO");
	}

	return 0;
}