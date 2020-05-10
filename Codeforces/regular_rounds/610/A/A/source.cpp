#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long a, b, c, r;

		scanf("%lld %lld %lld %lld", &a, &b, &c, &r);

		long long temp;

		if (b > a)
		{
			temp = a;
			a = b;
			b = temp;
		}

		long long sol;
		long long adist, bdist;

		adist = abs(a - c) > r ? abs(a - c) - r : 0;
		bdist = abs(b - c) > r ? abs(b - c) - r : 0;

		if (a <= c&&b <= c || a >= c&&b >= c)
		{
			sol = abs(adist - bdist);
		}

		else
		{
			sol = adist + bdist;
		}

		printf("%lld\n", sol);
	}

	return 0;
}