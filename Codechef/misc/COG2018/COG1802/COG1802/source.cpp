#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n;
	long long p, h, cur = 0;
	vector<long long> mass;
	int i, j, acc = 0;
	int lb, ub;
	int q;

	mass.push_back(0);

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld %lld", &p, &h);

		for (j = acc + 1; j <= acc + h; j++)
		{
			mass.push_back(mass[j - 1] + p);
		}

		acc = j - 1;
	}

	scanf("%d", &q);

	for (i = 0; i < q; i++)
	{
		scanf("%d %d", &lb, &ub);

		printf("%lld\n", (mass[ub] - mass[lb]) * 10);
	}

	return 0;
}