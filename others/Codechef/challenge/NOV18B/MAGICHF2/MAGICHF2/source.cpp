#include<cstdio>

using namespace std;

int main()
{
	int t, z;
	long long n, k, temp;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%lld %lld", &n, &k);

		temp = 0;

		if (n != 2)
		{
			while (temp<k && n > 1)
			{
				n = n / 2 + n % 2 + !(n % 2) * !!(n % 4) * !!(n / 4) * !temp;
				temp++;
			}
		}

		printf("%.8lf\n", 1.0 / (double)n);
	}

	return 0;
}