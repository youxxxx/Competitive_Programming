#include<cstdio>

using namespace std;

int main()
{
	long long n, m, temp, sol;

	scanf("%I64d %I64d", &n, &m);

	if (n > m)
	{
		temp = n;
		n = m;
		m = temp;
	}

	if (n < 3 && m < 3)
	{
		sol = 0;
	}

	else if (n == 1)
	{
		if (!(m % 2))
		{
			if (!(m / 2 % 3))
			{
				sol = m;
			}

			else
			{
				sol = m - 2;
			}
		}

		else
		{
			temp = m % 6;

			if (temp >= 4)
			{
				temp = (temp - 3) * 2;
			}

			else
			{
				temp = 0;
			}

			sol = m / 6 * 6 + temp;
		}
	}

	else if (n == 2)
	{
		sol = n * (m / 2 * 2);
	}

	else
	{
		if ((n + m) % 2)
		{
			sol = n*m - 2;
		}

		else
		{
			if (n % 2 || m % 2)
			{
				sol = n*m - 1;
			}

			else
			{
				sol = n*m;
			}
		}
	}

	printf("%I64d", sol);

	return 0;
}