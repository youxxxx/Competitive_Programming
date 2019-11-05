#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	int x[4];
	int a, b, c;
	int i;

	for (i = 0; i < 4; i++)
	{
		scanf("%d", &x[i]);
	}

	sort(&x[0], &x[4]);

	for (i = 0; i < 3; i++)
	{
		printf("%d ", x[3] - x[i]);
	}

	return 0;
}