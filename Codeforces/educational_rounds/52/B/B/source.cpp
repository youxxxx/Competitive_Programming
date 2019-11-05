#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	long long n, m;
	long long min, max;

	scanf("%I64d %I64d", &n, &m);

	if (m == 0)
	{
		printf("%I64d %I64d", n, n);
	}

	else
	{
		if (m * 2 >= n)
		{
			min = 0;
		}

		else
		{
			min = n - m * 2;
		}

		max = (long long)((double)n - (0.5 + (sqrt(1.0 + 4.0*(double)m*2.0)) / 2.0));

		printf("%I64d %I64d", min, max);
	}

	return 0;
}