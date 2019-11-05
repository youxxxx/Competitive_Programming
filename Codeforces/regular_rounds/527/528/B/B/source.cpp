#include<cstdio>

using namespace std;

int main()
{
	int n, k;
	int i;
	int min;
	int div, cand;

	scanf("%d %d", &n, &k);

	min = n*k + 1;

	for (i = 2; i < k; i++)
	{
		if (n%i)
		{
			continue;
		}

		div = n / i;

		cand = div*k + i;

		if (cand < min)
		{
			min = cand;
		}
	}

	printf("%d\n", min);

	return 0;
}