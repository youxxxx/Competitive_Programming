#include<cstdio>

using namespace std;

int main()
{
	long long int n, k, diff, res;

	scanf("%I64d %I64d", &n, &k);

	diff = k - 1 - n;

	if (diff < 0)
	{
		diff = 0;
	}

	res = k / 2 - !(k % 2) - diff;

	if (res < 0)
	{
		res = 0;
	}

	printf("%I64d", res);

	return 0;
}