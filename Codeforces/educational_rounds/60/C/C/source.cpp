#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long x1, y1;
	long long x2, y2;
	long long curx, cury;
	long long min = 9999999999;
	int n;
	int i;
	long long dx[4] = { 0,0,-1,1 };
	long long dy[4] = { 1,-1,0,0 };
	long long init;
	long long period;
	long long cur, prev;
	long long lmin;
	long long sol;
	long long q;
	long long xdiff, ydiff;
	int dir;
	char input[100002];
	string str;

	scanf("%I64d %I64d", &x1, &y1);
	scanf("%I64d %I64d", &x2, &y2);

	scanf("%d", &n);
	scanf("%s", input);

	str = input;

	curx = x1;
	cury = y1;

	init = (abs(x2 - x1) + abs(y2 - y1));

	prev = init;

	lmin = init;

	for (i = 0; i < n; i++)
	{
		switch (str[i])
		{
		case 'U':
			dir = 0;
			break;
		case 'D':
			dir = 1;
			break;
		case 'L':
			dir = 2;
			break;
		case 'R':
			dir = 3;
			break;
		}

		curx += dx[dir];
		cury += dy[dir];

		cur = abs(x2 - curx) + abs(y2 - cury);

		if (cur <= i + 1)
		{
			printf("%d\n", i + 1);

			return 0;
		}

		if (cur - (i + 1) < min)
		{
			min = cur - (i + 1);
		}
	}

	if (cur >= init)
	{
		printf("-1\n");

		return 0;
	}

	xdiff = curx - x1;
	ydiff = cury - y1;

	period = (init - cur);

	sol = n;

	if (cur > init - min)
	{
		q = (cur - (init - min)) / period;

		sol += q*period;

		curx += q*xdiff;
		cury += q*ydiff;
	}

	for (i = 0; i < 3 * n; i++)
	{
		switch (str[i])
		{
		case 'U':
			dir = 0;
			break;
		case 'D':
			dir = 1;
			break;
		case 'L':
			dir = 2;
			break;
		case 'R':
			dir = 3;
			break;
		}

		curx += dx[dir];
		cury += dy[dir];

		cur = abs(x2 - curx) + abs(y2 - cury);

		if (cur <= i + 1)
		{
			printf("%d\n", sol + (i + 1));

			return 0;
		}
	}
}