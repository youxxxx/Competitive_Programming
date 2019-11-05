#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n, s;

	scanf("%I64d %I64d", &n, &s);

	printf("%I64d", (s + n - 1) / n);

	return 0;
}