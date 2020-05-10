#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	if (n < m)
	{
		for (int i = 0; i < m; i++)
		{
			printf("%d", n);
		}
	}

	else
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d", m);
		}
	}

	printf("\n");

	return 0;
}