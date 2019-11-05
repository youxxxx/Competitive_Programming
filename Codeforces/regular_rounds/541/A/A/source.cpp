#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

int main()
{
	long long w1, h1, w2, h2;
	long long sol;

	scanf("%I64d %I64d %I64d %I64d", &w1, &h1, &w2, &h2);

	sol = (w1 + 2) * 2 + h1 * 2 - w2;
	sol += w2 + 2 + (h2 - 1) * 2;

	printf("%I64d\n", sol);

	return 0;
}