#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int a, b;
	int res = -20000;

	scanf("%d %d", &a, &b);

	if (a + b > res)
	{
		res = a + b;
	}
	if (a - b > res)
	{
		res = a - b;
	}

	if (a * b > res)
	{
		res = a * b;
	}

	printf("%d\n", res);

	return 0;
}