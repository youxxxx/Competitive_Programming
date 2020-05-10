#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n;

	scanf("%lld", &n);

	printf("%lld\n", n*(n - 1) / 2);

	return 0;
}