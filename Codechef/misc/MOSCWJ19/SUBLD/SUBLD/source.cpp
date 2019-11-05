#include<cstdio>
#include<cmath>

long long bin_search(long long k, long long lb, long long ub)
{
	long long base, rem, top;
	long long next, temp;
	long long pw;
	long long cnt = 0;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	temp = next;

	while (temp >= 10)
	{
		pw = (long long)log10(temp);

		base = (long long)pow(10.0, pw);

		top = temp / base;

		rem = temp - base*top;

		cnt += rem / top + 1;

		temp -= top * (rem / top + 1);
	}

	cnt += 2;

	if (cnt > k)
	{
		return bin_search(k, lb, next);
	}

	return bin_search(k, next, ub);
}

int main()
{
	int t, z;
	long long k;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%lld", &k);

		printf("%lld\n", bin_search(k, k, k * 9));
	}

	return 0;
}