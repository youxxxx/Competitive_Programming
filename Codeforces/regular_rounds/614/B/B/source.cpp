#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	long long n;

	scanf("%lld", &n);

	double sol = 0.0;

	for (long long i = 1; i <= n; i++)
	{
		sol += (double)1 / (double)i;
	}

	printf("%.8lf\n", sol);

	return 0;
}