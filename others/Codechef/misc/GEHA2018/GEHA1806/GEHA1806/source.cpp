#include<cstdio>
#include<set>
#include<map>

using namespace std;

int main()
{
	int n, q;
	int i, j;
	int x;
	int input;
	long long cnt;
	int *arr;
	map<int, pair<long long,long long>> s[2];
	map<int, pair<long long,long long>>::iterator it, ret;
	map<int, long long> sum;
	map<int, long long>::iterator ret2;
	int value;

	scanf("%d %d", &n, &q);

	arr = new int[n];

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	s[0].insert(pair<int, pair<long long, long long>>(arr[0], pair<long long, long long>(1, 1)));

	sum[arr[0]] = 1;

	for (j = 1; j < n; j++)
	{
		for (it = s[!(j % 2)].begin(); it != s[!(j % 2)].end(); it++)
		{
			value = it->first&arr[j];

			ret = s[j % 2].find(value);

			if (ret == s[j % 2].end())
			{
				s[j % 2][value] = pair<long long, long long>(it->second.first + it->second.second, it->second.second);
			}

			else
			{
				ret->second.first += it->second.first + it->second.second;

				ret->second.second += it->second.second;
			}

			/*
			if (value == x)
			{
				cnt += (long long)(it->second.first + it->second.second);
			}
			*/
			ret2 = sum.find(value);

			if (ret2 == sum.end())
			{
				sum[value] = it->second.first + it->second.second;
			}

			else
			{
				ret2->second += it->second.first + it->second.second;
			}
		}

		ret = s[j % 2].find(arr[j]);

		if (ret == s[j % 2].end())
		{
			s[j % 2][arr[j]] = pair<long long, long long>(1, 1);
		}

		else
		{
			ret->second.first++;

			ret->second.second++;
		}

		ret2 = sum.find(arr[j]);

		if (ret2 == sum.end())
		{
			sum[arr[j]] = 1;
		}

		else
		{
			ret2->second++;
		}

		s[!(j % 2)].clear();
	}

	for (i = 0; i < q; i++)
	{
		scanf("%d", &x);

		ret2 = sum.find(x);

		if (ret2 == sum.end())
		{
			printf("0\n");
		}

		else
		{
			printf("%lld\n", ret2->second);
		}

		cnt = 0;		
	}

	return 0;
}