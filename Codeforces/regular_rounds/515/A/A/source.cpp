#include<cstdio>

using namespace std;

int main()
{
	long long i, t;
	long long n, v, l, r;

	scanf("%I64d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%I64d %I64d %I64d %I64d", &n, &v, &l, &r);

		printf("%I64d\n", n / v - r / v + (l - 1) / v);
	}

	return 0;
}