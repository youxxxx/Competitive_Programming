#include<cstdio>

using namespace std;

int main()
{
	int t, z;
	long long l1, r1, l2, r2;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%I64d %I64d %I64d %I64d", &l1, &r1, &l2, &r2);

		if (r1 <= l2)
		{
			printf("%I64d %I64d\n", l1, r2);
		}

		else if(r2<=l1)
		{
			printf("%I64d %I64d\n", r1, l2);
		}

		else
		{
			if (l1 <= l2)
			{
				printf("%I64d %I64d\n", l1, r2);
			}

			else
			{
				printf("%I64d %I64d\n", r1, l2);
			}
		}
	}

	return 0;
}