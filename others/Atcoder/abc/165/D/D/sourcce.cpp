#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	long long a, b, n;

	scanf("%lld %lld %lld", &a, &b, &n);

	if (n >= b)
	{
		n = b - 1;
	}

	printf("%lld\n", a*n / b - n / b*a);

	return 0;
}