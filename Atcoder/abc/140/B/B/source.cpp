#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int a[21], b[21], c[21];
	int i;
	int sol = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d", &c[i]);
	}

	sol += b[a[0] - 1];

	for (i = 1; i < n; i++)
	{
		sol += b[a[i] - 1];

		if (a[i - 1] + 1 == a[i])
		{
			sol += c[a[i - 1] - 1];
		}
	}

	printf("%d\n", sol);

	return 0;
}