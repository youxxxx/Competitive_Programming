#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long a, b, c;
	long long lmax, ls;

	scanf("%lld %lld %lld", &a, &b, &c);

	if (a == b)
	{
		lmax = a;
		ls = a;
	}

	else if (a > b)
	{
		lmax = b + 1;
		ls = b;
	}

	else
	{
		lmax = a + 1;
		ls = a;
	}

	printf("%lld\n", c * 2 + lmax + ls);

	return 0;
}
