#include<cstdio>

using namespace std;

int main()
{
	int z, t;
	long long l, r, sum;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%I64d %I64d", &l, &r);

		sum = (r - l + 1) / 2 - r * ((r - l + 1) % 2);

		if (!(l % 2))
		{
			sum = -sum;
		}

		printf("%I64d\n", sum);
	}

	return 0;
}