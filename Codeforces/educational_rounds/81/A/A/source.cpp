#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		if (n % 2)
		{
			printf("7");
		}

		else
		{
			printf("1");
		}

		for (int i = 0; i < (n - 2) / 2; i++)
		{
			printf("1");
		}

		printf("\n");
	}

	return 0;
}