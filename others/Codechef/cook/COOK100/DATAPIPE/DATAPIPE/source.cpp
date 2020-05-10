#include<cstdio>

int main()
{
	int t, z;
	long long m, oe, of;
	long long i;
	long long cnt;
	long long lb, rm, last;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%lld %lld %lld", &m, &oe, &of);

		if (of > oe)
		{
			printf("%lld\n", 0);

			continue;
		}

		cnt = 0;

		for (i = 1; i <= (m + oe - 1) / oe; i++)
		{
			lb = oe - ((oe - 1) / i);

			if (lb < of)
			{
				cnt += i;
			}

			else if (lb == of)
			{
				rm = (oe % i);

				cnt += i - rm;	
			}
		}

		last = (m + m - 1) % oe + 1;

		lb = oe - (oe - 1) / (m / oe) + last / (m / oe) + 1;
		rm = last % (m / oe);

		if (lb < of)
		{
			cnt -= (m / oe);
		}

		else if (lb == of)
		{
			cnt -= (m / oe) - rm;
		}

		printf("%lld\n", cnt);
	}

	return 0;
}