#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

bool func(const pair<long long, int> &a, const pair<long long, int> &b)
{
	return a.first < b.first;
}

int main()
{
	int n;
	vector<pair<long long,int>> arr;
	long long input;
	int i;
	int sol;
	long long val;
	int idx;

	scanf("%d", &n);

	if (n <= 3)
	{
		printf("1\n");

		return 0;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(make_pair(input, i + 1));
	}

	sort(arr.begin(), arr.end(), func);

	for (i = 2; i < n - 1; i++)
	{
		if (arr[i + 1].first - arr[i].first != arr[2].first - arr[0].first)
		{
			break;
		}
	}

	if (i == n - 1)
	{
		printf("%d\n", arr[1].second);

		return 0;
	}

	for (i = 2; i < n - 1; i++)
	{
		if (arr[i + 1].first - arr[i].first != arr[2].first - arr[1].first)
		{
			break;
		}
	}

	if (i == n - 1)
	{
		printf("%d\n", arr[0].second);

		return 0;
	}

	sol = arr[0].second;
	val = arr[1].first - arr[0].first;
	
	for (i = 1; i < n - 1; i++)
	{
		if (arr[i + 1].first - arr[i].first != val)
		{
			break;
		}
	}

	if (i == n - 1)
	{
		printf("%d\n", arr[0].second);

		return 0;
	}

	idx = i;

	if (idx == n - 2)
	{
		printf("%d\n", arr[n - 1].second);

		return 0;
	}

	if (arr[idx + 2].first - arr[idx].first == val)
	{
		for (i = idx + 2; i < n - 1; i++)
		{
			if (arr[i + 1].first - arr[i].first != val)
			{
				break;
			}
		}

		if (i == n - 1)
		{
			printf("%d\n", arr[idx + 1].second);
		}

		else
		{
			printf("-1\n");
		}
	}

	else
	{
		printf("-1\n");
	}

	return 0;
}