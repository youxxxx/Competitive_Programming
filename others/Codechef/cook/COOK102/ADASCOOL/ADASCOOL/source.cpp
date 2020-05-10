#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	int t;
	int n, m;
	int z;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &m);

		if (n % 2 && m % 2)
		{
			printf("NO\n");
		}

		else
		{
			printf("YES\n");
		}
	}

	return 0;
}