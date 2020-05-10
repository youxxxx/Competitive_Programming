#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

long long bin_search(long long lb, long long ub, long long target, long long add)
{
	long long next, val;

	long long cand;

	if (ub - lb < 2)
	{
		cand = ub * 4 + add + 1;

		val = cand*(cand + 1) / 2;

		if (val >= target)
		{
			return cand;
		}

		return cand + 1;
	}

	next = (lb + ub) / 2 + (lb + ub) % 2;

	cand = next * 4 + add + 1;

	val = cand*(cand + 1) / 2;

	if (val >= target)
	{
		return bin_search(lb, next, target, add);
	}

	cand = next * 4 + add + 2;

	val = cand*(cand + 1) / 2;

	if (val >= target)
	{
		return cand;
	}

	return bin_search(next, ub, target, add);
}

int main()
{
	long long cases;

	scanf("%lld", &cases);

	for (long long tc = 0; tc < cases; tc++)
	{
		long long a, b;
		long long diff;

		scanf("%lld %lld", &a, &b);

		diff = abs(a - b);

		if (diff == 0)
		{
			printf("0\n");

			continue;
		}

		printf("%lld\n", bin_search(-1, (diff + 3) / 4, diff, !(diff % 2) * 2));
	}

	return 0;
}