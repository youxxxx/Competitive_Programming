#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

long long bsearch(long long lb, long long ub, long long a)
{
	long long next;
	long long val;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (ub + lb) / 2;

	val = a*next - (long long)pow(2.0, double(next)) + 1;

	if (val < 0)
	{
		return bsearch(lb, next, a);
	}

	return bsearch(next, ub, a);
}

long long bsearch2(long long lb, long long ub, long long a)
{
	long long next;
	long long val;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (ub + lb) / 2;

	val = a - (long long)pow(2.0, double(next - 1));

	if (val <= 0)
	{
		return bsearch2(lb, next, a);
	}

	return bsearch2(next, ub, a);
}

int main()
{
	int t, z;
	long long input;
	long long lb, ub;
	long long sol, sol2;
	long long sol0;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%lld", &input);

		lb = 4;

		ub = 36;

		sol0 = bsearch(lb, ub, input);

		sol = bsearch2(3, 31, input);

		sol2 = input*sol - (long long)pow(2.0, double(sol)) + 1;

		if (input*(sol - 1) - (long long)pow(2.0, double(sol - 1)) + 1 == sol2)
		{
			sol--;
		}

		printf("%lld %lld\n", sol0, sol);
	}

	return 0;
}