#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	if (n == 1)
	{
		printf("-1\n");
	}

	else
	{
		printf("%d %d\n", n, n);
	}

	return 0;
}