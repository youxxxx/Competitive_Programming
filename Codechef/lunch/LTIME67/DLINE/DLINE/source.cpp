#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool func(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.first < b.first || a.first == b.first&& a.second < b.second;
}

int main()
{
	int t, z;
	long long y, s, e;
	long long n, p;
	long long i, j, k;
	long long ptr;
	vector<pair<long long, long long>> arr;
	vector<long long> min, temp;
	long long max, base;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%lld %lld", &n, &p);

		for (i = 0; i < n; i++)
		{
			scanf("%lld %lld %lld", &y, &s, &e);

			arr.push_back(pair<long long, long long>(y, e));
		}

		sort(arr.begin(), arr.end(), func);

		min.push_back(0);

		max = 0;

		for (i = 0; i < n; i++)
		{
			ptr = i + 1;

			while (ptr < n && arr[ptr].first == arr[i].first)
			{
				ptr++;
			}

			base = arr[i].first;

			for (j = i; j < ptr; j++)
			{
				for (k = 0; k < min.size(); k++)
				{
					if (base + min[k] + arr[j].second <= p && max < k + j - i + 1)
					{
						max = k + j - i + 1;
					}
				}
			}

			for (j = 0; j < ptr - i; j++)
			{
				min.push_back(-1);
			}

			for (j = min.size() - 1 - (ptr - i); j >= 0; j--)
			{
				for (k = ptr - 1; k >= i; k--)
				{
					if (min[j] + arr[k].second * 2 + base <= p && (min[j + k - i + 1] == -1 || min[j + k - i + 1] > min[j] + arr[k].second * 2))
					{
						min[j + k - i + 1] = min[j] + arr[k].second * 2;
					}
				}
			}

			for (j = min.size() - 1; j >= 0; j--)
			{
				if (min[j] == -1)
				{
					min.erase(min.begin() + j);
				}
			}

			i = ptr - 1;
		}

		printf("%lld\n", max);

		min.clear();
		arr.clear();
	}

	return 0;
}