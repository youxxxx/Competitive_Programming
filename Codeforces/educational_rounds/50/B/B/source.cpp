#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	long long int n, m, k;
	long long int q, r, min, max;
	long long int t, i;

	scanf("%I64d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%I64d %I64d %I64d", &n, &m, &k);

		q = (n + m) / 2;
		r = (n + m) % 2;

		min = n;
		max = m;

		if (m < min)
		{
			min = m;
			max = n;
		}

		if (n > k || m > k)
		{
			printf("-1\n");
		}

		else if(!r)
		{
			printf("%I64d\n", k - 2 * ((k - max) % 2));
		}

		else
		{
			printf("%I64d\n", k - 1);
		}
	}

	return 0;
}