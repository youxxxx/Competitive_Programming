#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int a[3];

	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		if (a[i] == a[(i + 1) % 3] && a[(i + 1) % 3] != a[(i + 2) % 3])
		{
			printf("Yes\n");

			return 0;
		}
	}

	printf("No\n");

	return 0;
}