#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int t, z;
	long long n;
	vector<long long> mon;
	long long sum;
	long long i, j;
	long long input;
	long long yb, mb, db;
	long long yc, mc, dc;
	long long bdate, cdate;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%lld", &n);

		mon.push_back(0);

		sum = 0;

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			mon.push_back(input + mon.back());

			sum += input;
		}

		scanf("%lld %lld %lld", &yb, &mb, &db);
		scanf("%lld %lld %lld", &yc, &mc, &dc);

		bdate = (yb - 1)*sum + mon[mb - 1] + db + (yb - 1) / 4;

		cdate = (yc - 1)*sum + mon[mc - 1] + dc + (yc - 1) / 4;

		printf("%lld\n", cdate - bdate + 1);

		mon.clear();
	}

	return 0;
}