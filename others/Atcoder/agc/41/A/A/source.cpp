#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n, a, b;

	scanf("%lld %lld %lld", &n, &a, &b);

	if (!(abs(a - b) % 2))
	{
		printf("%lld\n", abs(a - b) / 2);
	}

	else
	{
		long long cand, temp;

		if (a > b)
		{
			temp = a;
			a = b;
			b = temp;
		}

		cand = a + (b - a) / 2;

		if ((n - b + 1) + (b - a) / 2 < cand)
		{
			cand = (n - b + 1) + (b - a) / 2;
		}

		printf("%lld\n", cand);
	}

	return 0;
}