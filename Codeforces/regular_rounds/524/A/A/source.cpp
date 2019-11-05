#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n, k;

	scanf("%I64d %I64d", &n, &k);

	printf("%I64d", (2 * n + k - 1) / k + (5 * n + k - 1) / k + (8 * n + k - 1) / k);

	return 0;
}