#include<cstdio>

#define MAX 1000000000

using namespace std;

int main()
{
	int t, z;
	long long x0, y0, x1, y1;
	long long input;
	long long ll, ul, lr;
	long long xmid, ymid;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		printf("Q 0 0\n");
		fflush(stdout);

		scanf("%lld", &input);

		ll = input;

		printf("Q 1000000000 0\n");
		fflush(stdout);

		scanf("%lld", &input);

		ul = -input + MAX;

		printf("Q 0 1000000000\n");
		fflush(stdout);

		scanf("%lld", &input);

		lr = -input + MAX;

		xmid = (ll + ul) / 2;
		ymid = (ll + lr) / 2;

		printf("Q %lld 0\n", xmid);
		fflush(stdout);

		scanf("%lld", &input);

		y0 = input;

		printf("Q %lld 1000000000\n", xmid);
		fflush(stdout);

		scanf("%lld", &input);

		y1 = -input + MAX;

		printf("Q 0 %lld\n", ymid);
		fflush(stdout);

		scanf("%lld", &input);

		x0 = input;

		printf("Q 1000000000 %lld\n", ymid);
		fflush(stdout);

		scanf("%lld", &input);

		x1 = -input + MAX;

		printf("A %lld %lld %lld %lld\n", x0, y0, x1, y1);
		fflush(stdout);

		scanf("%lld", &input);

		if (input != 1)
		{
			return 0;
		}
	}

	return 0;
}