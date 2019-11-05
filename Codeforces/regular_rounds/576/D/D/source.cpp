#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	long long n, m;
	vector<long long> arr;
	long long ub = 0;
	bool fixed[200001] = { 0, };
	long long i, j;
	long long input, input2, input3;
	vector<pair<long long, pair<long long, long long>>> query;
	long long val1, val2;

	arr.push_back(0);

	scanf("%lld", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);
	}

	scanf("%lld", &m);

	for (i = 0; i < m; i++)
	{
		scanf("%lld", &input);

		if (input == 1)
		{
			scanf("%lld %lld", &input2, &input3);

			query.push_back(make_pair(input, make_pair(input2, input3)));
		}

		else
		{
			scanf("%lld", &input2);

			query.push_back(make_pair(input, make_pair(input2, 0)));
		}
	}

	for (i = m - 1; i >= 0; i--)
	{
		val1 = query[i].second.first;
		val2 = query[i].second.second;

		if (query[i].first == 1)
		{
			if (!fixed[val1])
			{
				fixed[val1] = true;

				arr[val1] = val2 > ub ? val2 : ub;
			}
		}

		else
		{
			if (val1 > ub)
			{
				ub = val1;
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		if (!fixed[i])
		{
			if (ub > arr[i])
			{
				arr[i] = ub;
			}
		}

		printf("%lld ", arr[i]);
	}

	return 0;
}