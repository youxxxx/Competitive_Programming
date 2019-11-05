#include<cstdio>

using namespace std;

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	if (n + 1 >= k * 2)
	{
		printf("YES\n");
	}

	else
	{
		printf("NO\n");
	}

	return 0;
}