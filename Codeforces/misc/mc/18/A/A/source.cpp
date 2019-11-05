#include<cstdio>
#include<cmath>
#include<vector>
#include<string>

using namespace std;

int main()
{
	long long int n, res;

	scanf("%I64d", &n);

	res = (long long int)log2((double)n) + 1;

	printf("%I64d", res);

	return 0;
}