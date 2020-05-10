#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	long long n;
	long long k;
	vector<long long> arr, div;
	map<long long, long long> list;
	map<long long, long long>::iterator it, ret;
	long long input;
	long long sum = 0, tot, tot2;
	long long ub;
	long long i, j;

	scanf("%lld %lld", &n, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);

		sum += input;
	}

	ub = (long long)sqrt((double)sum);

	for (i = 1; i <= ub; i++)
	{
		if (!(sum%i))
		{
			div.push_back(i);
		}
	}

	if (ub*ub == sum)
	{
		for (i = (long long)div.size() - 2; i >= 0; i--)
		{
			div.push_back(sum / div[i]);
		}
	}

	else
	{
		for (i = (long long)div.size() - 1; i >= 0; i--)
		{
			div.push_back(sum / div[i]);
		}
	}

	for (i = div.size() - 1; i >= 1; i--)
	{
		list.clear();

		tot = 0;
		tot2 = 0;

		for (j = 0; j < n; j++)
		{
			if (!(arr[j] % div[i]))
			{
				continue;
			}

			ret = list.find(arr[j] % div[i]);

			if (ret == list.end())
			{
				list[arr[j] % div[i]] = 1;
			}

			else
			{
				ret->second++;
			}

			tot += div[i] - (arr[j] % div[i]);
		}

		for (it = list.begin(); it != list.end(); it++)
		{
			for (j = 0; j < it->second; j++)
			{
				tot -= div[i] - it->first;
				tot2 += it->first;

				if (tot == tot2)
				{
					break;
				}
			}

			if (j != it->second)
			{
				break;
			}
		}

		if (tot <= k)
		{
			printf("%lld\n", div[i]);

			return 0;
		}
	}

	printf("1\n");

	return 0;
}