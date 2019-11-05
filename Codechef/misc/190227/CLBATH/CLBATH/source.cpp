#include<cstdio>

using namespace std;

int main()
{
	long long v[3], t[3];
	long long i;
	long long lmax;
	long long tot;
	long long en0, en1;
	long long tc, z;

	scanf("%lld", &tc);

	for (z = 0; z < tc; z++)
	{
		for (i = 0; i < 3; i++)
		{
			scanf("%lld %lld", &v[i], &t[i]);
		}

		if (v[2] > v[0] + v[1])
		{
			printf("NO\n");

			continue;
		}

		if (t[2] == t[0])
		{
			if (v[0] >= v[2])
			{
				printf("YES\n");
			}

			else
			{
				printf("NO\n");
			}

			continue;
		}

		if (t[2] == t[1])
		{
			if (v[1] >= v[2])
			{
				printf("YES\n");
			}

			else
			{
				printf("NO\n");
			}

			continue;
		}

		if (t[2] > t[1] || t[2] < t[0])
		{
			printf("NO\n");

			continue;
		}

		tot = t[2] * v[2];

		if (v[0] < v[2])
		{
			en0 = t[0] * v[0] + t[1] * (v[2] - v[0]);
		}

		else
		{
			en0 = t[0] * v[2];
		}

		if (v[1] < v[2])
		{
			en1 = t[1] * v[1] + t[0] * (v[2] - v[1]);
		}

		else
		{
			en1 = t[1] * v[2];
		}

		if (tot<en0 || tot>en1)
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