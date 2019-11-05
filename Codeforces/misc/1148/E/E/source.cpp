#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool func(const pair<pair<long long, long long>, long long> &a, const pair<pair<long long, long long>, long long> &b)
{
	return a.first.first < b.first.first;
}

bool func2(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.first < b.first;
}

int main()
{
	int n;
	int i;
	int ptr;
	vector<pair<pair<long long, long long>, long long>> arr, moves;
	vector<pair<long long, long long>> s;
	long long input;
	long long diff = 0;
	vector<long long> t;
	long long left, len;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		s.push_back(pair<long long, long long>(input, i + 1));
	}

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		t.push_back(input);

		diff += s[i].first - t[i];
	}

	if (diff != 0)
	{
		printf("NO\n");

		return 0;
	}

	sort(s.begin(), s.end(), func2);
	sort(t.begin(), t.end());

	for (i = 0; i < n; i++)
	{
		if (s[i].first != t[i])
		{
			arr.push_back(pair<pair<long long, long long>, long long>(pair<long long, long long>(s[i].first, t[i]), s[i].second));
		}
	}

	ptr = arr.size() - 1;

	//sort(arr.begin(), arr.end(), func);

	for (i = 0; i < arr.size() - 1; i++)
	{
		if (ptr == i)
		{
			break;
		}

		if (arr[ptr].first.second > arr[ptr].first.first)
		{
			printf("NO\n");

			return 0;
		}

		if (arr[i].first.first == arr[i].first.second)
		{
			continue;
		}

		if (arr[i].first.first > arr[i].first.second)
		{
			printf("NO\n");

			return 0;
		}

		left = arr[i].first.second - arr[i].first.first;

		while (ptr != i)
		{
			if (arr[ptr].first.second > arr[ptr].first.first)
			{
				printf("NO\n");

				return 0;
			}

			if (arr[ptr].first.second == arr[ptr].first.first)
			{
				ptr--;

				continue;
			}

			len = left < (arr[ptr].first.first - arr[i].first.first) / 2 ? left : (arr[ptr].first.first - arr[i].first.first) / 2;

			len = len < arr[ptr].first.first - arr[ptr].first.second ? len : arr[ptr].first.first - arr[ptr].first.second;

			moves.push_back(pair<pair<long long, long long>, long long>(pair<long long, long long>(arr[i].second, arr[ptr].second), len));

			arr[ptr].first.first -= len;
			arr[i].first.first += len;

			left -= len;

			if (left == 0)
			{
				if (arr[ptr].first.second == arr[ptr].first.first)
				{
					ptr--;
				}

				break;
			}

			ptr--;
		}

		if (ptr == i)
		{
			break;
		}
	}
	for (i = 0; i < arr.size(); i++)
	{
		if (arr[i].first.first != arr[i].first.second)
		{
			printf("NO\n");

			return 0;
		}
	}

	printf("YES\n%d\n", moves.size());

	for (i = 0; i < moves.size(); i++)
	{
		printf("%lld %lld %lld\n", moves[i].first.first, moves[i].first.second, moves[i].second);
	}

	return 0;
}