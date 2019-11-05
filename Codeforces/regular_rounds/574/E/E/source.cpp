#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

class comp
{
public:
	bool operator() (const pair<long long, long long> &a, const pair<long long, long long> &b)
	{
		return a.first > b.first;
	}
};

bool func(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.first < b.first;
}

int main()
{
	vector<long long> emp, l, r;
	vector<vector<long long>> lmin, arr, preproc;
	long long n, m, a, b;
	long long i, j, k;
	long long g, x, y, z;
	long long cur, curmin, gmin;
	long long sol = 0;
	long long pivot, len;

	scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
	scanf("%lld %lld %lld %lld", &g, &x, &y, &z);
	cur = g;


	for (i = 0; i < n; i++)
	{
		arr.push_back(emp);

		for (j = 0; j < m; j++)
		{
			arr.back().push_back(cur);

			cur = (cur*x + y) % z;
		}
	}

	for (i = 0; i < n; i++)
	{
		lmin.push_back(emp);

		for (j = b - 1; j < m; j += b)
		{
			l.clear();
			r.clear();

			curmin = arr[i][j];

			l.push_back(curmin);

			for (k = 1; k < b; k++)
			{
				if (arr[i][j - k] < curmin)
				{
					curmin = arr[i][j - k];
				}

				l.push_back(curmin);
			}

			curmin = arr[i][j];

			r.push_back(curmin);

			for (k = 1; k < b && j + k < m; k++)
			{
				if (arr[i][j + k] < curmin)
				{
					curmin = arr[i][j + k];
				}

				r.push_back(curmin);
			}

			for (k = 0; k < r.size(); k++)
			{
				gmin = l[b - k - 1] < r[k] ? l[b - k - 1] : r[k];

				lmin.back().push_back(gmin);
			}
		}
	}

	for (i = 0; i <= m - b; i++)
	{
		for (j = a - 1; j < n; j += a)
		{
			l.clear();
			r.clear();

			curmin = lmin[j][i];

			l.push_back(curmin);

			for (k = 1; k < a; k++)
			{
				if (lmin[j - k][i] < curmin)
				{
					curmin = lmin[j - k][i];
				}

				l.push_back(curmin);
			}

			curmin = lmin[j][i];

			r.push_back(curmin);

			for (k = 1; k < a && j + k < n; k++)
			{
				if (lmin[j + k][i] < curmin)
				{
					curmin = lmin[j + k][i];
				}

				r.push_back(curmin);
			}

			for (k = 0; k < r.size(); k++)
			{
				gmin = l[a - k - 1] < r[k] ? l[a - k - 1] : r[k];

				sol += gmin;
			}
		}
	}

	printf("%lld\n", sol);

	return 0;
}