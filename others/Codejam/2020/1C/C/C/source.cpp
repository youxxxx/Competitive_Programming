#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 1; tc <= cases; tc++)
	{
		long long n, d;
		long long lmax;

		scanf("%lld %lld", &n, &d);

		lmax = 1;

		map<long long,long long> list;
		vector<long long> arr;

		for (long long i = 0; i < n; i++)
		{
			long long input;

			scanf("%lld", &input);

			arr.push_back(input);
		}

		for (long long i = 0; i < n; i++)
		{
			map<long long,long long>::iterator ret;

			ret = list.find(arr[i]);

			if (ret == list.end())
			{
				list[arr[i]] = 1;
			}

			else
			{
				ret->second++;
			}
		}

		for (map<long long,long long>::iterator it = list.begin(); it != list.end(); it++)
		{
			if (it->second >= d)
			{
				lmax = d;

				break;
			}
		}

		if (lmax == 1 && d >= 3)
		{
			for (map<long long,long long>::iterator it = list.begin(); it != list.end(); it++)
			{
				vector<pair<long long, long long>> v1, v2;

				long long tot = 0;

				for (map<long long, long long>::iterator it2 = it; it2 != list.end(); it2++)
				{
					if (!(it2->first%it->first))
					{
						v1.push_back({ it2->first,it2->second });

						tot += it2->second;
					}

					else
					{
						v2.push_back({ it2->first,it2->second });

						tot += it2->second;
					}
				}

				const long long base = it->first;

				long long lb = 0, ub;

				ub = (d + tot - 1) / (tot);

				for (long long next = (lb + ub) / 2 + (lb + ub) % 2; lb < ub - 1; next = (lb + ub) / 2)
				{
					long long slice = 0, profit = 0;

					for (long long i = 0; i < v1.size(); i++)
					{
						long long get;

						get = v1[i].first / base*next;

						if (slice + get >= d)
						{
							if (slice + get == d)
							{
								profit++;
							}

							slice = d;

							break;
						}

						profit++;

						slice += get;
					}

					if (slice < d)
					{
						for (long long i = 0; i < v2.size(); i++)
						{
							long long get;

							get = v2[i].first * next / base;

							if (slice + get >= d)
							{
								slice = d;

								break;
							}

							slice += get;
						}
					}

					if (slice == d)
					{
						ub = next;
					}

					else
					{
						lb = next;
					}
				}

				long long slice = 0, profit = 0;

				for (long long i = 0; i < v1.size(); i++)
				{
					long long get;

					get = v1[i].first / base*ub;

					if (slice + get >= d)
					{
						if (slice + get == d)
						{
							profit++;
						}

						slice = d;

						break;
					}

					profit++;

					slice += get;
				}

				if (slice < d)
				{
					for (long long i = 0; i < v2.size(); i++)
					{
						long long get;

						get = v2[i].first * ub / base;

						if (slice + get >= d)
						{
							slice = d;

							break;
						}

						slice += get;
					}
				}

				if (profit > lmax)
				{
					lmax = profit;
				}
			}
		}

		printf("Case #%d: %lld\n", tc, d - lmax);
	}

	return 0;
}