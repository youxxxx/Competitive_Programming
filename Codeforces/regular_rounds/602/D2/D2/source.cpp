#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

#define N 200001

using namespace std;

int fw[N] = { 0, };

void add(int x)
{
	for (; x <= N; x += (x&-x))
	{
		fw[x]++;
	}
}

int get(int x)
{
	int rvalue = 0;

	for (; x; x ^= (x&-x))
	{
		rvalue += fw[x];
	}

	return rvalue;
}

int bin_search(int lb, int ub, int target)
{
	int next;

	if (ub - lb < 2)
	{
		return ub;
	}

	next = (lb + ub) / 2 + (lb + ub) % 2;

	if (get(next) < target)
	{
		return bin_search(next, ub, target);
	}

	return bin_search(lb, next, target);
}

bool func(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first > b.first || a.first == b.first&&a.second < b.second;
}

bool func2(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second < b.second;
}

int main()
{
	int n;
	vector<pair<int, int>> arr;
	int val[N];

	//freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		arr.push_back(make_pair(input, i + 1));

		val[i + 1] = input;
	}

	sort(arr.begin(), arr.end(), func);

	vector<pair<pair<int, int>, int>> query;
	int m;

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int size, pos;

		scanf("%d %d", &size, &pos);

		query.push_back(make_pair(make_pair(size, pos), i));
	}

	sort(query.begin(), query.end());

	int ptr = 0;
	vector<pair<int, int>>::iterator it;
	int sol[N];

	for (int i = 0; i < m; i++)
	{
		vector<pair<int, int>>::iterator ret;

		for (int j = ptr; j < query[i].first.first; j++)
		{
			add(arr[j].second);

			ptr++;
		}

		sol[query[i].second] = val[bin_search(0, n, query[i].first.second)];
	}

	for (int i = 0; i < m; i++)
	{
		printf("%d\n", sol[i]);
	}

	return 0;
}