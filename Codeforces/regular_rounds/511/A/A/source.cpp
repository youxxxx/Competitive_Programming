#include<cstdio>

using namespace std;

int main()
{
	int n, a, b, c;
	int r1, r2;

	scanf("%d", &n);

	a = b = c = n / 3;

	r2 = n % 3;
	r1 = a % 3;

	if (r1 == 0)
	{
		if (r2 == 0)
		{
			a--;
			b--;
			c += 2;
		}

		else if (r2 == 1)
		{
			a--;
			b++;
			c++;
		}

		else
		{
			a--;
			b++;
			c += 2;
		}
	}

	else if (r1 == 1)
	{
		if (r2 == 1)
		{
			c++;
		}

		else if (r2 == 2)
		{
			b++;
			c++;
		}
	}

	else
	{
		if (r2 == 1)
		{
			a--;
			c += 2;
		}

		else if(r2==2)
		{
			c += 2;
		}
	}

	printf("%d %d %d", a, b, c);

	return 0;
}
