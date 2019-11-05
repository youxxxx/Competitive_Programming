#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

#define MOD 1000000007

using namespace std;

int main()
{
	long long x, y, z;
	long long sol;

	scanf("%lld %lld %lld", &x, &y, &z);

	if (x / z + y / z == (x + y) / z)
	{
		printf("%lld 0\n", (x + y) / z);
	}

	else
	{
		sol = (z - x%z) < (z - y%z) ? (z - x%z) : (z - y%z);
		
		printf("%lld %lld\n", (x + y) / z, sol);
	}

	return 0;
}