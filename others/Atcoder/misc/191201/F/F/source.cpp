#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

#define MOD 1000000007

using namespace std;

int main()
{
	long long t1, t2;
	long long a1, a2;
	long long b1, b2;

	//("input.txt", "r", stdin);

	scanf("%lld %lld %lld %lld %lld %lld", &t1, &t2, &a1, &a2, &b1, &b2);

	if (a1 == b1)
	{
		printf("infinity");

		return 0;
	}

	long long da1, da2, db1, db2, diff1, diff2;

	da1 = t1*a1;
	da2 = t2*a2;
	db1 = t1*b1;
	db2 = t2*b2;

	diff1 = da1 - db1;
	diff2 = diff1 + da2 - db2;

	if (diff2 == 0)
	{
		printf("infinity");

		return 0;
	}

	if (diff1 < 0 && diff2 < 0 || diff1>0 && diff2>0)
	{
		printf("0\n");

		return 0;
	}

	long long sol;

	sol = abs(diff1) / abs(diff2) * 2 + !!(abs(diff1) % abs(diff2));

	printf("%lld\n", sol);

	return 0;
}