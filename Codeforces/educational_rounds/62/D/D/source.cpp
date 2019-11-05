#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<functional>

using namespace std;

int main()
{
	long long n;
	long long i;
	long long lmin;
	long long cur = 0;

	scanf("%I64d", &n);

	for (i = 2; i < n; i++)
	{
		cur += (i*(i + 1));
	}

	printf("%I64d\n", cur);

	return 0;
}