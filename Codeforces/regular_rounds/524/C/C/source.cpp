#include<cstdio>

using namespace std;

int main()
{
	int z, t;
	long long n, m;
	long long x1, x2, y1, y2, x3, x4, y3, y4;
	long long white;
	long long z1, z2, z3, z4;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%I64d %I64d", &n, &m);

		scanf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

		white = n*m / 2;

		if (n % 2 && m % 2)
		{
			white++;
		}

		if ((x2 - x1 + 1) % 2 && (y2 - y1 + 1) % 2 && ((x1 + y1) % 2))
		{
			white++;
		}

		white += (x2 - x1 + 1) * (y2 - y1 + 1) / 2;

		if ((x4 - x3 + 1) % 2 && (y4 - y3 + 1) % 2 && !((x3 + y3) % 2))
		{
			white--;
		}

		white -= (x4 - x3 + 1) * (y4 - y3 + 1) / 2;

		z2 = x2 < x4 ? x2 : x4;
		z4 = y2 < y4 ? y2 : y4;
		z1 = x1 > x3 ? x1 : x3;
		z3 = y1 > y3 ? y1 : y3;

		if (z2 >= z1&&z4 >= z3)
		{
			if ((z2 - z1 + 1) % 2 && (z4 - z3 + 1) % 2 && ((z1 + z3) % 2))
			{
				white--;
			}

			white -= (z2 - z1 + 1)*(z4 - z3 + 1) / 2;
		}

		printf("%I64d %I64d\n", white, n*m - white);
	}

	return 0;
}