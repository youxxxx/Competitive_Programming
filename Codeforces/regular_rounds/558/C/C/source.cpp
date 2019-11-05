#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

long long gcd(long long a, long long b)
{
	long long temp;

	a = abs(a);
	b = abs(b);

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
	long long n;
	vector<pair<long long, long long>> point;
	vector<pair<long long, long long>> slope;
	vector<pair<long long, long long>> emp;
	vector<vector<pair<long long, long long>>> origin;
	set<long long> h, v;
	set<long long>::iterator it, ret;
	long long i, j, k, l;
	long long input1, input2;
	long long div;
	long long x, y;
	long long cnt = 0;
	long long sol = 0;

	//freopen("input.txt", "r", stdin);

	scanf("%I64d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d %I64d", &input1, &input2);

		point.push_back(pair<long long, long long>(input1, input2));
	}

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			x = point[j].first - point[i].first;
			y = point[j].second - point[i].second;

			if (x == 0)
			{
				ret = v.find(point[i].first);

				if (ret == v.end())
				{
					v.insert(point[i].first);

					continue;
				}

				continue;
			}

			if (y == 0)
			{
				ret = h.find(point[i].second);

				if (ret==h.end())
				{
					h.insert(point[i].second);

					continue;
				}

				continue;
			}

			div = gcd(x, y);

			x /= div;
			y /= div;

			if (x < 0)
			{
				x *= -1;
				y *= -1;
			}

			for (k = 0; k < slope.size(); k++)
			{
				if (slope[k].first == x&&slope[k].second == y)
				{
					for (l = 0; l < origin[k].size(); l++)
					{
						if (origin[k][l].first == point[i].first&&origin[k][l].second == point[i].second)
						{
							break;
						}

						div = (origin[k][l].first - point[i].first) / slope[k].first;

						if (div == 0)
						{
							continue;
						}

						if (slope[k].first*div == (origin[k][l].first - point[i].first) && slope[k].second*div == (origin[k][l].second - point[i].second))
						{
							break;
						}

						/*
						if (div == 0)
						{
							origin[k].push_back(pair<long long, long long>(point[i].first, point[i].second));

							break;
						}
						*/
					}

					if (l == origin[k].size())
					{
						origin[k].push_back(pair<long long, long long>(point[i].first, point[i].second));
					}

					break;
				}
			}

			if (k == slope.size())
			{
				slope.push_back(pair<long long, long long>(x, y));

				origin.push_back(emp);

				origin.back().push_back(pair<long long, long long>(point[i].first, point[i].second));
			}
		}
	}

	for (i = 0; i < slope.size(); i++)
	{
		cnt += origin[i].size();
	}

	sol += (long long)h.size()*((long long)v.size() + cnt);
	sol += (long long)v.size()*cnt;

	for (i = 0; i < slope.size() - 1; i++)
	{
		cnt -= origin[i].size();

		sol += cnt*(long long)origin[i].size();
	}

	printf("%I64d\n", sol);

	return 0;
}