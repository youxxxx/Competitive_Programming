#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<functional>

using namespace std;

vector <pair<long long, long long>> range;
long long n;
long long lmin, lmax;
long long s;

long long bin_search(long long lb, long long ub)
{
	long long large = 0, avail = 0;
	long long next;
	bool found = false;
	long long i, j;
	long long temp;
	vector<long long> plus;
	long long sum;

	temp = s;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	if (1)
	{
		for (i = 0; i < n; i++)
		{
			if (range[i].second < next)
			{
				temp -= range[i].first;
			}

			else if (next < range[i].first)
			{
				temp -= range[i].first;

				large++;
			}

			else
			{
				if (range[i].first == next)
				{
					temp -= range[i].first;

					large++;
				}

				else
				{
					temp -= range[i].first;

					plus.push_back(next - range[i].first);

					avail++;
				}
			}

			if (temp < 0)
			{
				break;
			}
		}

		if (i == n)
		{
			if (large > n / 2)
			{
				found = true;
			}

			else if (large + avail > n / 2)
			{
				sort(plus.begin(), plus.end());

				for (j = 0; j < n / 2 + 1 - large; j++)
				{
					temp -= plus[j];

					if (temp < 0)
					{
						break;
					}
				}

				if (temp >= 0)
				{
					found = true;
				}
			}
		}
	}

	if (found)
	{
		return bin_search(next, ub);
	}

	return bin_search(lb, next);
}

int main()
{
	long long tc, cases;
	long long i;

	//freopen("input.txt", "r", stdin);

	scanf("%lld", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%lld %lld", &n, &s);

		range.clear();

		lmin = 9999999999;
		lmax = 0;

		for (i = 0; i < n; i++)
		{
			long long input1, input2;

			scanf("%lld %lld", &input1, &input2);

			range.push_back(pair<long long, long long>(input1, input2));

			if (input1 < lmin)
			{
				lmin = input1;
			}

			if (input2 > lmax)
			{
				lmax = input2;
			}
		}

		printf("%lld\n", bin_search(lmin, lmax + 1));
	}

	return 0;
}