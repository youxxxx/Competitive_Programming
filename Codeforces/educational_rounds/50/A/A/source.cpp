#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	long long int n, k;

	scanf("%I64d %I64d", &n, &k);

	printf("%I64d", k / n + !!(k%n));

	return 0;
}