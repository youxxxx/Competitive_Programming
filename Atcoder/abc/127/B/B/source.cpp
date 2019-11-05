#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	long long r, d;
	long long a;
	long long x;
	int i;

	scanf("%lld %lld %lld", &r, &d, &a);

	x = a;

	for (i = 0; i < 10; i++)
	{
		x = r*x - d;

		printf("%lld\n", x);
	}

	return 0;
}