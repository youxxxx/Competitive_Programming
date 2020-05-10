#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	long long n;

	scanf("%lld", &n);

	long long d3, d5, d15, tot;

	d3 = n / 3;
	d5 = n / 5;
	d15 = n / 15;

	tot = n*(n + 1) / 2 - d3*(d3 + 1) / 2 * 3 - d5*(d5 + 1) / 2 * 5 + d15 * (d15 + 1) / 2 * 15;

	printf("%lld\n", tot);

	return 0;
}