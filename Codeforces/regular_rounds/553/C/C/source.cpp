#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

#define MOD 1000000007

using namespace std;

bool func(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.second - a.first < b.second - b.first;
}

int main()
{
	long long l, r;
	long long lb, ub;
	long long lcnt, rcnt;
	long long sol = 0;
	long long i;
	long long size, mid, prod, sub, prev, psize, pmid, prod2;

	lb = 1;
	lcnt = 0;

	scanf("%I64d %I64d", &l, &r);

	while (lb < l)
	{
		lb = (lb + 1) * 2 - 1;

		lcnt++;
	}

	ub = lb;
	rcnt = lcnt;

	while (ub <= r)
	{
		ub = (ub + 1) * 2 - 1;
		
		rcnt++;
	}

	if (ub > r)
	{
		ub /= 2;
		rcnt--;
	}

	for (i = lcnt; i < rcnt; i++)
	{
		if (i % 2)
		{
			size = (long long)(pow)(4.0, (i / 2)) * 2;

			if (size == 2)
			{
				mid = 3;
			}

			else
			{
				mid = (size - 2) / 3 * 2 + size + 1;
			}

			prod = ((mid%MOD)*(size%MOD)) % MOD;

			sol = (sol + prod) % MOD;
		}

		else
		{
			size = (long long)(pow)(4.0, (i / 2));

			if (size == 1)
			{
				mid = 1;
			}

			else
			{
				mid = (size - 1) / 3 * 2 + size + 1;
			}

			prod = ((mid%MOD)*(size%MOD)) % MOD;

			sol = (sol + prod) % MOD;
		}
	}

	if (lb > l)
	{
		i = lcnt - 1;

		if (i % 2)
		{
			size = (long long)(pow)(4.0, (i / 2)) * 2;

			if (size == 2)
			{
				mid = 3;
			}

			else
			{
				mid = (size - 2) / 3 * 2 + size + 1;
			}

			prod = ((mid%MOD)*(size%MOD)) % MOD;

			psize = l - ((long long)(pow(2.0, i + 1)) - 1) - 1;

			pmid = ((size - 2) / 3 * 2) + psize + 2;

			prod2 = ((pmid%MOD)*(psize%MOD)) % MOD;

			sol = (sol + prod) % MOD;

			sol = (sol + MOD - prod2) % MOD;
		}

		else
		{
			size = (long long)(pow)(4.0, (i / 2));

			if (size == 1)
			{
				mid = 1;
			}

			else
			{
				mid = (size - 1) / 3 * 2 + size + 1;
			}

			prod = ((mid%MOD)*(size%MOD)) % MOD;

			psize = l - ((long long)(pow(2.0, i + 1)) - 1) - 1;

			pmid = ((size - 1) / 3 * 2) + psize + 1;

			prod2 = ((pmid%MOD)*(psize%MOD)) % MOD;

			sol = (sol + prod) % MOD;

			sol = (sol + MOD - prod2) % MOD;
		}
	}

	if (ub < r)
	{
		i = rcnt;

		if (i % 2)
		{
			size = (long long)(pow)(4.0, (i / 2)) * 2;

			if (size == 2)
			{
				mid = 3;
			}

			else
			{
				mid = (size - 2) / 3 * 2 + size + 1;
			}

			prod = ((mid%MOD)*(size%MOD)) % MOD;

			psize = r - ((long long)(pow(2.0, i)) - 1);

			pmid = ((size - 2) / 3) * 2 + psize + 2;

			prod2 = ((pmid%MOD)*(psize%MOD)) % MOD;

			sol = (sol + prod2) % MOD;
		}

		else
		{
			size = (long long)(pow)(4.0, (i / 2));

			if (size == 1)
			{
				mid = 1;
			}

			else
			{
				mid = (size - 1) / 3 * 2 + size + 1;
			}

			prod = ((mid%MOD)*(size%MOD)) % MOD;

			psize = r - ((long long)(pow(2.0, i)) - 1);

			pmid = ((size - 1) / 3 * 2) + psize + 1;

			prod2 = ((pmid%MOD)*(psize%MOD)) % MOD;

			sol = (sol + prod2) % MOD;
		}
	}

	printf("%I64d\n", sol);

	return 0;
}