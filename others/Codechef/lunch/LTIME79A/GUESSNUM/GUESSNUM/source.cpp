#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

long long bin_search(long long lb, long long ub, long long target, long long mult, long long divd)
{
	long long next;

	if (ub - lb < 2)
	{
		return ub;
	}

	next = (lb + ub) / 2 + (lb + ub) % 2;

	if (next / (target - mult*next) >= divd)
	{
		return bin_search(lb, next, target, mult, divd);
	}

	return bin_search(next, ub, target, mult, divd);
}

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long a, n;

		scanf("%lld %lld", &a, &n);

		long long lb, ub;

		lb = n / (a + 1);

		if (lb*(a + 1) < n)
		{
			lb++;
		}

		ub = n / a;

		if (ub*a + 1 > n)
		{
			ub--;
		}

		vector<long long> sol;
		long long cur;
		cur = lb;

		for (long long i = 1; i <= ub; i++)
		{
			cur = bin_search(cur - 1, ub, n, a, i);

			if (!(cur%(n-cur*a)))
			{
				sol.push_back(cur++);
			}

			if (cur >= ub)
			{
				if (cur == ub && i != ub && !(ub % (n - ub*a)))
				{
					sol.push_back(ub);
				}

				break;
			}
		}

		printf("%d\n", sol.size());

		for (int i = 0; i < sol.size(); i++)
		{
			printf("%d ", sol[i]);
		}

		printf("\n");
	}

	return 0;
}