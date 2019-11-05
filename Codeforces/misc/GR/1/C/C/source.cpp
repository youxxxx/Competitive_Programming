#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

bool func(long long &a, long long &b)
{
	return a > b;
}

int main()
{
	long long sum;
	long long a, temp;
	long long base;
	long long r;
	long long full;
	long long lmax;
	long long i;
	long long found;

	int t, z;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		base = 1;

		scanf("%I64d", &a);

		temp = a;

		full = false;

		sum = 0;

		while (temp)
		{
			r = temp % 2;

			if (r == 0)
			{
				full = true;
			}

			temp /= 2;

			sum += base;

			base *= 2;
		}

		if (full)
		{
			printf("%I64d\n", sum);

			continue;
		}

		lmax = (long long)sqrt((double)sum);

		found = false;

		for (i = 3; i <= lmax; i++)
		{
			if (!(sum%i))
			{
				printf("%I64d\n", sum / i);

				found = true;

				break;
			}
		}

		if (!found)
		{
			printf("1\n");
		}
	}

	return 0;
}