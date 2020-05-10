#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long a, b, k;

	scanf("%lld %lld %lld", &a, &b, &k);

	long long subt;
	subt = a < k ? a : k;
	a -= subt;
	k -= subt;
	subt = b < k ? b : k;
	b -= subt;
	k -= subt;

	printf("%lld %lld\n", a, b);

	return 0;
}