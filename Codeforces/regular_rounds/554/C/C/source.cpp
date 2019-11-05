#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

long long gcd(long long a, long long b)
{
	long long temp;

	while (b != 0)
	{
		a %= b;
		
		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	long long a, b;
	long long diff;
	long long temp;
	vector<long long> divd;
	long long i, ub;
	long long lmin, cand, mink;
	long long ak, bk;
	long long k;

	scanf("%I64d %I64d", &a, &b);

	if (abs(a - b) <= 1)
	{
		printf("0\n");

		return 0;
	}

	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}

	diff = b - a;

	divd.push_back(1);

	ub = (long long)sqrt(double(diff));

	for (i = 2; i <= ub; i++)
	{
		if (!(diff%i))
		{
			divd.push_back(i);
		}
	}

	if (ub*ub == diff)
	{
		for (i = divd.size() - 2; i >= 0; i--)
		{
			divd.push_back(diff / divd[i]);
		}
	}

	else
	{
		for (i = divd.size() - 1; i >= 0; i--)
		{
			divd.push_back(diff / divd[i]);
		}
	}

	lmin = a / gcd(a, b)*b;
	mink = 0;

	for (i = 1; i < divd.size(); i++)
	{
		if (!(a%divd[i]))
		{
			continue;
		}

		k = (divd[i] - (a%divd[i]));

		ak = a + k;
		bk = b + k;

		cand = ak / gcd(ak, bk)*bk;

		if (cand < lmin || cand == lmin && k < mink)
		{
			lmin = cand;
			mink = k;
		}
	}

	printf("%I64d\n", mink);

	return 0;
}