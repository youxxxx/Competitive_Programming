#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	long long t, s, a, b, c;
	long long i;

	scanf("%I64d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%I64d %I64d %I64d %I64d", &s, &a, &b, &c);

		printf("%I64d\n", s / c + s / c / a*b);
	}

	return 0;
}