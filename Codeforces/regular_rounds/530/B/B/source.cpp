#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	long long n;
	long long max;
	long long i;
	long long min = 1000000000;
	long long cand;

	scanf("%I64d", &n);

	max = (long long)(sqrt((double)n));

	for (i = max + 1; i >= 1; i--)
	{
		cand = i + n / i;

		if (n%i)
		{
			cand++;
		}

		if (cand < min)
		{
			min = cand;
		}
	}

	printf("%I64d\n", min);

	return 0;
}