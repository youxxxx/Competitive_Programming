#include<cstdio>

using namespace std;

long long numofp(long long *size, long long *patty, long long cur, long long left)
{
	if (cur == 0)
	{
		return left;
	}

	if (left <= 1)
	{
		return 0;
	}

	if (left >= 2 && left <= size[cur - 1] + 1)
	{
		return numofp(size, patty, cur - 1, left - 1);
	}

	if (left == size[cur - 1] + 2)
	{
		return patty[cur - 1] + 1;
	}

	if (left >= size[cur - 1] + 3 && left <= size[cur] - 1)
	{
		return patty[cur - 1] + 1 + numofp(size, patty, cur - 1, left - size[cur - 1] - 2);
	}

	return patty[cur];
}

int main()
{
	long long size[51];
	long long patty[51];
	long long n, x;
	long long i;

	size[0] = 1;
	patty[0] = 1;

	scanf("%lld %lld", &n, &x);

	for (i = 1; i <= n; i++)
	{
		size[i] = size[i - 1] * 2 + 3;
		patty[i] = patty[i - 1] * 2 + 1;
	}

	printf("%lld\n", numofp(size, patty, n, x));

	return 0;
}