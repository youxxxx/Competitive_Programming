#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>

using namespace std;

struct coord
{
	long long x;
	long long y;
	long long z;
	int idx;
};

struct row
{
	vector<coord> points;
	vector<long long> xpos;
};

struct plane
{
	long long zpos;
	vector<row> rows;
	vector<long long> ypos;
};

bool func(coord &a, coord &b)
{
	return a.x < b.x || a.x == b.x&&a.y < b.y || a.x == b.x&&a.y == b.y&&a.z < b.z;
}

struct slope
{
	int start;
	int end;
	long long lmin;
	long long lmax;
};

int main()
{
	vector<long long> arr;
	long long input;
	int n;
	int i, j;
	long long lmin = 999999999, lmax = 0;
	int ptr;
	long long curmax;
	int lidx;
	int sol[100001];
	int cnt = 0;
	int newstart, newend;
	vector<slope> s;
	slope cur;
	deque<slope> dq;

	memset(sol, -1, sizeof(sol));

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);

		if (input < lmin)
		{
			lmin = input;
		}

		if (input > lmax)
		{
			lmax = input;
		}
	}

	if (lmin * 2 >= lmax)
	{
		for (i = 0; i < n; i++)
		{
			printf("-1 ");
		}

		return 0;
	}

	for (i = 0; i < n; i++)
	{
		if (arr[(i + 1) % n] < arr[i])
		{
			ptr = (i + 1) % n;

			break;
		}
	}

	lidx = ptr;
	cur.start = ptr;
	cur.end = ptr;
	cur.lmin = arr[ptr];
	cur.lmax = arr[ptr];
	
	for (i = 1; i < n; i++)
	{
		if (arr[(ptr + i) % n] < arr[(ptr + i + n - 1) % n])
		{
			s.push_back(cur);

			cur.start = (ptr + i) % n;
			cur.lmin = arr[(ptr + i) % n];
			cur.lmax = arr[(ptr + i) % n];
		}

		else
		{
			cur.end = (ptr + i) % n;
			cur.lmax = arr[(ptr + i) % n];
		}
	}

	s.push_back(cur);

	dq.push_back(s[0]);

	for (i = 1; i < s.size(); i++)
	{
		while (!dq.empty() && dq.back().lmax > s[i].lmin * 2)
		{
			if (dq.back().start > dq.back().end)
			{
				for (j = dq.back().start; j < n; j++)
				{
					sol[j] = s[i].start + n - j;

					if (sol[j] < 0)
					{
						sol[j] += n;
					}

					sol[j] %= n;
				}

				for (j = 0; j <= dq.back().end; j++)
				{
					sol[j] = s[i].start - j;

					if (sol[j] < 0)
					{
						sol[j] += n;
					}

					sol[j] %= n;
				}
			}

			else
			{
				for (j = dq.back().start; j <= dq.back().end; j++)
				{
					sol[j] = s[i].start - j;

					if (sol[j] < 0)
					{
						sol[j] += n;
					}

					sol[j] %= n;
				}
			}

			dq.pop_back();
		}

		newstart = s[i].start;
		newend = s[i].end;
		cur.lmin = s[i].lmin;

		while (!dq.empty() && dq.front().lmax < s[i].lmax)
		{
			newstart = dq.front().start;

			dq.pop_front();

			cur.lmin = s[i].lmin;
		}

		cur.start = newstart;
		cur.end = newend;
		cur.lmax = s[i].lmax;

		dq.push_front(cur);
	}

	for (i = 0; i < n * 2 && !dq.empty(); i++)
	{
		while (!dq.empty() && dq.back().lmax > s[i%n].lmin * 2)
		{
			if (dq.back().start > dq.back().end)
			{
				for (j = dq.back().start; j < n; j++)
				{
					sol[j] = s[i%n].start + n - j;

					if (sol[j] < 0)
					{
						sol[j] += n;
					}

					sol[j] %= n;
				}

				for (j = 0; j <= dq.back().end; j++)
				{
					sol[j] = s[i%n].start - j;

					if (sol[j] < 0)
					{
						sol[j] += n;
					}

					sol[j] %= n;
				}
			}

			else
			{
				for (j = dq.back().start; j <= dq.back().end; j++)
				{
					sol[j] = s[i%n].start - j;

					if (sol[j] < 0)
					{
						sol[j] += n;
					}

					sol[j] %= n;
				}
			}

			dq.pop_back();
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", sol[i]);
	}
	
	return 0;
}