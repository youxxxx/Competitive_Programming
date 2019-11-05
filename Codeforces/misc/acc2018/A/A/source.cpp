#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n;

	scanf("%I64d", &n);

	if (n <= 2)
	{
		printf("%I64d\n", n);
	}

	else
	{
		printf("1\n", n);
	}

	return 0;
}