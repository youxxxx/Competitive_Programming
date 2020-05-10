#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

int main()
{
	long long h;

	scanf("%lld", &h);

	long long sol;

	sol = (long long)pow(2.0, (long long)log2(h) + 1) - 1;

	printf("%lld\n", sol);

	return 0;
}