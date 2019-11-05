#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool func(pair<int, int> &a, pair<int, int> &b)
{
	return a.first > b.first || a.first == b.first&&a.second < b.second;
}

int bin_search(vector<pair<int, int>> &list, vector<int> &arr, int lb, int ub, int k)
{
	int i;
	int cnt = 0;
	int next;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	for (i = 0; i < 200001; i++)
	{
		cnt += list[i].first / next;

		if (cnt >= k)
		{
			break;
		}
	}

	if (cnt >= k)
	{
		return bin_search(list, arr, next, ub, k);
	}

	return bin_search(list, arr, lb, next, k);
}

int main()
{
	int n, k;
	vector<int> arr;
	int input;
	vector<pair<int, int>> list;
	int take;
	int i, j;

	scanf("%d %d", &n, &k);

	for (i = 0; i < 200001; i++)
	{
		list.push_back(pair<int, int>(0, i));
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		list[input].first++;
	}

	sort(list.begin(), list.end(), func);
	/*
	for (i = 0; i < 200000; i++)
	{
		if (arr.size() == k || list[i].first == 0)
		{
			break;
		}

		take = 0;

		while (take < list[i].first && arr.size() < k && (take == 0 || list[i].first / (take + 1) >= list[i + 1].first))
		{
			arr.push_back(list[i].second);

			take++;
		}

		list[i].first -= take;
	}

	if (arr.size() < k)
	{
		sort(list.begin(), list.end(), func);

		for (i = 0; i < 200001 && i < k - arr.size(); i++)
		{
			for (j = 0; j < list[i].first; j++)
			{
				arr.push_back(list[i].second);
			}
		}
	}
	*/

	take = bin_search(list, arr, 1, (n + k * 2 + 1) / k, k);

	for (i = 0; i < 200001; i++)
	{
		for (j = 0; j < list[i].first / take; j++)
		{
			arr.push_back(list[i].second);

			if (arr.size() == k)
			{
				break;
			}
		}

		if (arr.size() == k)
		{
			break;
		}
	}

	for (i = 0; i < k; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}