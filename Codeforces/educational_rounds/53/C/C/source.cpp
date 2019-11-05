#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	char *input;
	int n;
	int i, j;
	long long x, y;
	long long curx = 0, cury = 0;
	char target[2];

	string str;

	scanf("%d", &n);

	input = new char[n + 1];

	scanf("%s", input);

	str = input;

	scanf("%I64d %I64d", &x, &y);

	if (abs(x) + abs(y) > n || (abs(x) + abs(y) % 2) != n % 2)
	{
		printf("-1\n");

		return 0;
	}
	
	for (i = 0; i < n; i++)
	{
		switch (str[i])
		{
		case 'R':
			curx++;
			break;
		case 'L':
			curx--;
			break;
		case 'U':
			cury++;
			break;
		case 'D':
			cury--;
			break;
		}
	}

	if (abs(x-curx) + abs(y-cury) > n * 2 || (abs(x - curx) + abs(y - cury)) % 2)
	{
		printf("-1\n");

		return 0;
	}

	return 0;
}


/*
int main()
{
	char *input;
	int n;
	int i, j;
	long long cnt[4] = { 0, };
	long long pcnt[4];
	long long left[4];
	long long min[4] = { 0, };
	long long sol = 500000;
	long long x, y;
	long long curx, cury;
	long long xp, yp;
	long long xx, yy;
	long long temp;
	char target[2];
	string str;

	scanf("%d", &n);

	input = new char[n + 1];

	scanf("%s", input);

	str = input;

	scanf("%I64d %I64d", &x, &y);

	if (abs(x) + abs(y) > n || (abs(x) + abs(y) % 2) != n % 2)
	{
		printf("-1\n");

		return 0;
	}

	for (i = 0; i < n; i++)
	{
		switch (str[i])
		{
		case 'R':
			cnt[0]++;
			break;
		case 'L':
			cnt[1]++;
			break;
		case 'U':
			cnt[2]++;
			break;
		case 'D':
			cnt[3]++;
			break;
		}
	}

	if (x > 0)
	{
		min[0] = x;
	}

	else
	{
		min[1] = -x;
	}

	if (y > 0)
	{
		min[2] = y;
	}

	else
	{
		min[3] = -y;
	}
	
	curx = cnt[0] - cnt[1];
	cury = cnt[2] - cnt[3];

	xp = x - curx;
	yp = y - cury;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 4; j++)
		{
			pcnt[j] = 0;
		}

		for (j = i; j < n; j++)
		{
			switch (str[j])
			{
			case 'R':
				pcnt[0]++;
				break;
			case 'L':
				pcnt[1]++;
				break;
			case 'U':
				pcnt[2]++;
				break;
			case 'D':
				pcnt[3]++;
				break;
			}

			left[0] = pcnt[0];
			left[1] = pcnt[1];
			left[2] = pcnt[2];
			left[3] = pcnt[3];

			xx = xp;
			yy = yp;

			if (xp > 0)
			{
				if (left[0] * 2 > xx / 2 * 2)
				{
					left[0] -= xx / 2;

					xx -= xx / 2 * 2;
				}

				else
				{
					left[0] = 0;

					xx -= left[0] * 2;
				}
			}

			else if (xp < 0)
			{
				xx = -xx;

				if (left[1] * 2 > xx / 2 * 2)
				{
					left[1] -= xx / 2;

					xx -= xx / 2 * 2;
				}

				else
				{
					left[1] = 0;

					xx -= left[1] * 2;
				}
			}

			if (yp > 0)
			{
				if (left[2] * 2 > yy / 2 * 2)
				{
					left[2] -= yy / 2;

					yy -= yy / 2 * 2;
				}

				else
				{
					left[2] = 0;

					yy -= left[2] * 2;
				}
			}

			else if (yp < 0)
			{
				yy = -yy;

				if (left[3] * 2 > yy / 2 * 2)
				{
					left[3] -= yy / 2;

					yy -= yy / 2 * 2;
				}

				else
				{
					left[3] = 0;

					yy -= left[3] * 2;
				}
			}


		}
	}
}
*/