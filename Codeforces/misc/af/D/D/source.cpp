#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n;
	int i;
	int lmin = 33;
	int sol, prod = 0;
	int input;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if (i == 2)
		{
			prod = input;
		}

		if (input < lmin)
		{
			lmin = input;
		}
	}

	prod = prod^lmin;

	sol = 2 + prod;

	printf("%d\n", sol);

	return 0;
}