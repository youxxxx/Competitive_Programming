#include<cstdio>
#include<cmath>

using namespace std;

double bin(double lb, double ub, double target)
{
	double next;

	next = (lb + ub) / 2.0;

	if (abs(next*(target - next)-target) < 0.0000001)
	{
		return next;
	}

	else if (next*(target - next) > target)
	{
		return bin(next, ub, target);
	}

	else
	{
		return bin(lb, next, target);
	}
}

int main()
{
	int n;
	int t, z;
	double sol;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);
		
		if (n>0 &&n<4)
		{
			printf("N\n");
		}
		
		else if (n == 0 || n == 4)
		{
			printf("Y %d %d\n", n / 2, n / 2);
		}

		else
		{
			sol = bin((double)n / 2.0, (double)n, (double)n);
			printf("Y %.9lf %.9lf\n", sol, (double)n - sol);
		}
	}

	return 0;
}