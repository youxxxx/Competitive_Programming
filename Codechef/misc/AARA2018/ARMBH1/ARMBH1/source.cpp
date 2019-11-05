#include<cstdio>

using namespace std;

int main()
{
	int t, z;
	long long n, x, q;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%lld %lld", &x, &n);

		q = (n - 1) / x;

		printf("%lld\n", x*q*(q+1) / 2);
	}

	return 0;
}
