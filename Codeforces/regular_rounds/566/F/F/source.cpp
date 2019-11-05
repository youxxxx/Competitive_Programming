#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
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

long long target, acc;

bool func(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	long long lval, rval;

	lval = abs((a.first + acc) % (2 * target) - target);
	rval = abs((b.first + acc) % (2 * target) - target);

	return lval < rval || lval == rval&&a.second < b.second;
}

bool func2(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.first < b.first || a.first == b.first&&a.second < b.second;
}

long long lbsearch(vector<pair<long long, long long>> &list, long long target, long long lb, long long ub)
{
	long long next;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	if (list[next].first == target)
	{
		return next;
	}

	else if (list[next].first < target)
	{
		return lbsearch(list, target, next, ub);
	}

	else
	{
		return lbsearch(list, target, lb, next);
	}
}

long long ubsearch(vector<pair<long long, long long>> &list, long long target, long long lb, long long ub)
{
	long long next;

	if (ub - lb < 2)
	{
		return ub;
	}

	next = (lb + ub) / 2 + (lb + ub) % 2;

	if (list[next].first == target)
	{
		return next;
	}

	else if (list[next].first < target)
	{
		return ubsearch(list, target, next, ub);
	}

	else
	{
		return ubsearch(list, target, lb, next);
	}
}

int main()
{
	int t, z;
	long long a, b, p, q;
	long long g, temp;
	long long pw, prod;
	long long inv, cur;
	long long lb, ub, root;
	vector<pair<long long, long long>> list;
	vector<pair<long long, long long>>::iterator it, ret;
	long long lcand, ucand, tcand;
	long long lval, uval, tval;
	long long i, j;
	long long val;
	long long lmin, lidx;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		lmin = 9999999999;
		lidx = 9999999999;

		scanf("%lld %lld %lld %lld", &a, &b, &p, &q);

		if (q == 1 || a == b)
		{
			printf("%lld\n", a);

			continue;
		}
		 
		g = gcd(p, q);

		p /= g;
		q /= g;

		p %= q;

		root = (long long)sqrt((double)(b - a + 1));

		list.clear();

		for (j = 0; j < root; j++)
		{
			val = a + j;

			list.push_back(pair<long long, long long>(((2 * p) % (2 * q))*val % (2 * q), val));
		}

		acc = 0;
		target = q;

		sort(list.begin(), list.end(), func2);

		for (j = root - 1; j >= 1; j--)
		{
			if (list[j].first == list[j - 1].first)
			{
				list.erase(list.begin() + j);
			}
		}

		acc = 0;
		target = q;

		for (i = 0; i < (b - a + 1) / root; i++)
		{
			//sort(list.begin(), list.end(), func);
			/*
			for (j = 0; j < list.size(); j++)
			{
				if (abs((list[j].first + acc) % (2 * q) - target) < lmin)
				{
					lmin = abs((list[j].first + acc) % (2 * q) - target);

					lidx = list.front().second + root * i;
				}
			}
			*/

			lcand = lbsearch(list, (3 * q - acc) % (2 * q), 0, list.size());

			val = abs((list[(lcand + list.size() - 1) % list.size()].first + acc) % (2 * q) - target);

			if (val < lmin || val == lmin && list[(lcand + list.size() - 1) % list.size()].second + i * root < lidx)
			{
				lmin = val;
				lidx = list[(lcand + list.size() - 1) % list.size()].second + i * root;
			}

			val = abs((list[lcand].first + acc) % (2 * q) - target);

			if (val < lmin || val == lmin && list[lcand].second + i * root < lidx)
			{
				lmin = val;
				lidx = list[lcand].second + i * root;
			}

			val = abs((list[(lcand + 1) % list.size()].first + acc) % (2 * q) - target);

			if (val < lmin || val == lmin && list[(lcand + 1) % list.size()].second + i * root < lidx)
			{
				lmin = val;
				lidx = list[(lcand + 1) % list.size()].second + i * root;
			}

			acc = (acc + (2 * p)*root) % (2 * q);

			/*

			ucand = ubsearch(list, (3 * q - acc) % (2 * q), -1, list.size() - 1);

			lval = abs((3 * q - acc) % (2 * q) - list[lcand].first);
			uval = abs((3 * q - acc) % (2 * q) - list[ucand].first);
			tval = -1;

			if (ucand == list.size() - 1)
			{
				tcand = 0;

				tval = abs((3 * q - acc) % (2 * q) - list[tcand].first);
			}

			else if (lcand == 0)
			{
				tcand = list.size() - 1;

				tval = abs((3 * q - acc) % (2 * q) - list[tcand].first);
			}

			if (lcand == ucand || lval <= uval)
			{
				if (lval < lmin)
				{
					lmin = lval;
					lidx = list[lcand].second + i * root;
				}
			}

			else
			{
				if (uval < lmin)
				{
					lmin = uval;
					lidx = list[ucand].second + i * root;
				}
			}

			if (tval != -1 && tval < lmin)
			{
				lmin = tval;
				lidx = list[tcand].second + i * root;
			}
			*/
		}

		list.clear();

		acc = 0;

		for (i = a + (b - a + 1) / root*root; i <= b; i++)
		{
			list.push_back(pair<long long, long long>(((2 * p) % (2 * q))*i % (2 * q), i));
		}

		sort(list.begin(), list.end(), func);

		if (!list.empty() && abs((list.front().first + acc) % (2 * q) - target) < lmin)
		{
			lmin = abs((list.front().first + acc) % (2 * q) - target) < lmin;

			lidx = list.front().second;
		}

		printf("%lld\n", lidx);
	}

	return 0;
}