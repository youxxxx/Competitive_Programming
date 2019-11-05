#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool func(pair<long long, bool> &a, pair<long long, bool> &b)
{
	if (a.first < b.first || a.first==b.first&&a.second<b.second)
	{
		return true;
	}

	return false;
}

int main()
{
	int n, k;
	int level;
	int t, z;
	long long start, end;
	int i;
	vector<pair<long long, bool>> arr;
	long long prev, cur;
	long long opening;
	long long left;
	long long max;
	bool sat;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &k);

		for (i = 0; i < n; i++)
		{
			scanf("%lld %lld", &start, &end);

			arr.push_back(pair<long long, bool>(start, true));
			arr.push_back(pair<long long, bool>(end, false));
		}

		prev = 0;
		left = 0;
		max = 0;
		level = 0;
		sat = false;

		sort(arr.begin(), arr.end(), func);

		for (i = 0; i < n * 2; i++)
		{
			cur = arr[i].first;
			opening = arr[i].second;

			level += opening * 2 - 1;
			/*
			if (cur == prev)
			{
				continue;
			}
			*/
			if (sat && level < k)
			{
				if (cur - left > max)
				{
					max = cur - left;
				}

				left = cur;

				sat = false;
			}

			else if (level >= k && !sat)
			{
				left = cur;

				sat = true;
			}
		}

		printf("%lld\n", max);

		arr.clear();
	}

	return 0;
}