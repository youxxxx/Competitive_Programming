#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	int i;

	scanf("%d", &n);

	m = (2 * n + 4) / 4;

	printf("%d\n", m);

	for (i = 0; i < m; i++)
	{
		printf("1 %d\n", i + 1);
	}

	for (i = 0; i < n - m; i++)
	{
		printf("%d %d\n", m, i + 2);
	}

	return 0;
}