#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int i, j, k;
	int ub;
	char list[5] = { 'a','e','i','o','u' };

	scanf("%d", &n);

	ub = (int)sqrt((double)n);

	for (i = 5; i <= ub; i++)
	{
		if (!(n%i) && n / i >= 5)
		{
			for (j = 0; j < i; j++)
			{
				for (k = 0; k < n / i; k++)
				{
					printf("%c", list[(j + k) % 5]);
				}
			}

			printf("\n");

			return 0;
		}
	}

	printf("-1\n");

	return 0;
}