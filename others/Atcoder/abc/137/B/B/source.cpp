#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int k, x;
	int i;

	scanf("%d %d", &k, &x);

	for (i = x - k + 1; i <= x + k - 1; i++)
	{
		printf("%d ", i);
	}

	printf("\n");

	return 0;
}