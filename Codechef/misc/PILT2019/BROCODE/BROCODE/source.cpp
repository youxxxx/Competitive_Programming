#include<cstdio>
#include<vector>

using namespace std;

int n;
long long x, y, input;
vector<long long> arr;
long long lmin, lmax;

long long bsearch(long long lb, long long ub)
{
	int i;
	long long sum = 0;
	long long next;

	if (ub - lb < 2)
	{
		for (i = 0; i < n; i++)
		{
			if (arr[i] < ub)
			{
				sum += (ub - arr[i])*y;
			}

			else if (arr[i] > ub)
			{
				sum -= (arr[i] - ub)*x;
			}
		}

		return sum;
	}

	next = (lb + ub) / 2 + (lb + ub) % 2;

	for (i = 0; i < n; i++)
	{
		if (arr[i] < next)
		{
			sum += (next - arr[i])*y;
		}

		else if (arr[i] > next)
		{
			sum -= (arr[i] - next)*x;
		}
	}

	if (sum == 0)
	{
		return 0;
	}

	else if (sum < 0)
	{
		return bsearch(next, ub);
	}

	return bsearch(lb, next);
}

int main()
{
	int t, z;
	int i;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %lld %lld", &n, &x, &y);

		lmin = 10000000001, lmax = 0;

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			arr.push_back(input);

			if (input < lmin)
			{
				lmin = input;
			}

			if (input > lmax)
			{
				lmax = input;
			}
		}

		printf("%lld\n", bsearch(lmin - 1, lmax));

		arr.clear();
	}

	return 0;
}