#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

#define MOD 1000000007

using namespace std;

int main()
{
	long long x, y;
	long long xtimes, ytimes, tot;
	long long diff;
	vector <long long > bits;

	long long temp = MOD - 2;

	while (temp)
	{
		bits.push_back(temp % 2);

		temp /= 2;
	}

	scanf("%lld %lld", &x, &y);

	if ((x + y) % 3)
	{
		printf("0\n");

		return 0;
	}

	if (x < y)
	{
		temp = x;
		x = y;
		y = temp;
	}

	diff = x - y;

	tot = (x + y) / 3;

	xtimes = (tot + diff) / 2;
	ytimes = tot - xtimes;

	if (ytimes < 0)
	{
		printf("0\n");

		return 0;
	}

	long long perm = 1;

	for (long long i = ytimes+1; i <= xtimes + ytimes; i++)
	{
		perm = perm*i%MOD;
	}

	long long sol;

	sol = perm;

	perm = 1;

	for (long long i = 1; i <= xtimes; i++)
	{
		perm = perm*i%MOD;
	};

	temp = perm;

	long long div = 1;

	for (int i = 0; i < bits.size(); i++)
	{
		if (bits[i])
		{
			div = div*temp%MOD;
		}

		temp = temp*temp%MOD;
	}

	sol = sol*div%MOD;

	printf("%lld\n", sol);

	return 0;
}