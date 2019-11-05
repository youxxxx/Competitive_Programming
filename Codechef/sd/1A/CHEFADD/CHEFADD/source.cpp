#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

long long rec(vector<long long> &off, int acnt, int bcnt, int c, int curval, int curcnt, int curoff, int target, int lim)
{
	long long cnt = 0;
	int i;
	long long temp;

	if (curval > c)
	{
		return 0;
	}

	if (curcnt == target)
	{
		temp = c - curval;

		while (temp)
		{
			cnt += temp % 2;

			temp >>= 1;
		}

		if (cnt == bcnt)
		{
			return 1;
		}

		return 0;
	}

	if (target - curcnt < lim - curoff)
	{
		cnt += rec(off, acnt, bcnt, c, curval, curcnt, curoff + 1, target, lim);
	}

	cnt += rec(off, acnt, bcnt, c, curval + off[curoff], curcnt + 1, curoff + 1, target, lim);

	return cnt;
}

int main()
{
	vector<long long> off;
	int t;
	long long a, b, c;
	int i, j;
	long long base;
	int lim;
	int acnt, bcnt;
	long long temp;
	long long sol;

	scanf("%d", &t);

	base = 1;
	off.push_back(1);

	for (i = 0; i < 31; i++)
	{
		base *= 2;

		off.push_back(base);
	}

	for (i = 0; i < t; i++)
	{
		scanf("%lld %lld %lld", &a, &b, &c);

		acnt = 0;
		bcnt = 0;

		lim = -1;

		while (off[++lim] <= c);

		temp = a;

		while (temp)
		{
			acnt += temp % 2;

			temp >>= 1;
		}

		temp = b;

		while (temp)
		{
			bcnt += temp % 2;

			temp >>= 1;
		}

		sol = rec(off, acnt, bcnt, c, 0, 0, 0, acnt, lim);

		printf("%lld\n", sol);
	}

	return 0;
}