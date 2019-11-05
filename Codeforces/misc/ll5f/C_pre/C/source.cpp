#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

bool func(pair<long long, pair<long long, long long>> &a, pair<long long, pair<long long, long long>> &b)
{
	return a.first < b.first || a.first == b.first&&a.second.first < b.second.first;
}

long long bin_search(vector<long long> &arr, long long target, long long lb, long long ub)
{
	long long next;

	if (ub - lb <= 1)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	if (arr[next] == target)
	{
		return next;
	}

	if (arr[next] > target)
	{
		return bin_search(arr, target, lb, next);
	}

	return bin_search(arr, target, next, ub);
}

int main()
{
	vector<long long> vtrap;
	vector<pair<long long, pair<long long, long long>>> htrap;
	vector<long long> *cell;
	long long n, m;
	long long input, input2, input3;
	long long i, j;
	long long left;
	long long min;
	long long ptr, ptr2;
	long long pre;
	long long index;
	vector<pair<long long, long long>> dp[2];

	scanf("%I64d %I64d", &n, &m);
	cell = new vector<long long>[n + 1];

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		vtrap.push_back(input);
	}

	for (i = 0; i < m; i++)
	{
		scanf("%I64d %I64d %I64d", &input, &input2, &input3);

		htrap.push_back(pair<long long, pair<long long, long long>>(input3, pair<long long, long long>(input, input2)));
	}

	sort(vtrap.begin(), vtrap.end());
	sort(htrap.begin(), htrap.end(), func);

	left = 0;

	for (i = 0; i <= n; i++)
	{
		cell[i].push_back(0);
	}

	if (n == 0)
	{
		for (i = 0; i < m; i++)
		{
			if (htrap[i].second.first == 1 && htrap[i].second.second == 1000000000)
			{
				cell[0].push_back(htrap[i].first);
			}
		}
	}

	else
	{
		for (i = 0; i < m; i++)
		{
			//cell[i].push_back(0);

			/*
			for (j = 0; j < m; j++)
			{
			if (htrap[j].second.first - 1 <= left&&htrap[j].second.second >= vtrap[i])
			{
			cell[i].push_back(htrap[j].first);
			}
			}
			*/

			index = bin_search(vtrap, htrap[i].second.first - 1, 0, vtrap.size());

			for (j = index; j < n; j++)
			{
				if (htrap[i].second.second < vtrap[j])
				{
					break;
				}

				cell[j].push_back(htrap[i].first);
			}

			if (vtrap[n - 1] >= htrap[i].second.first - 1 && htrap[i].second.second == 1000000000)
			{
				cell[n].push_back(htrap[i].first);
			}

			//left = vtrap[i];
		}
	}

	/*
	cell[n].push_back(0);

	for (j = 0; j < m; j++)
	{
		if (htrap[j].second.first - 1<= left&&htrap[j].second.second >= 1000000000)
		{
			cell[n].push_back(htrap[j].first);
		}
	}
	*/

	for (j = 1; j < cell[0].size(); j++)
	{
		dp[0].push_back(pair<long long, long long>(j - 1, cell[0][j]));
	}

	min = cell[0].size() - 1;

	if (n==0 && m == 0 || min == 0)
	{
		printf("0\n");

		return 0;
	}

	for (i = 1; i <= n; i++)
	{
		if (dp[!(i % 2)][0].first + 1 >= min)
		{
			break;
		}

		if (cell[i].size()==1)
		{
			if (dp[!(i % 2)][0].first + 1 < min)
			{
				min = dp[!(i % 2)][0].first + 1;
			}

			break;
		}

		ptr = cell[i].size() - 1;
		ptr2 = dp[!(i % 2)].size() - 1;

		pre = ptr2;

		while (1)
		{
			while (ptr > 0 && cell[i][ptr] >= dp[!(i % 2)][ptr2].second)
			{
				ptr--;
			}

			while (ptr2 > 0 && cell[i][ptr] < dp[!(i % 2)][ptr2 - 1].second)
			{
				ptr2--;
			}

			/*
			while (ptr > 0 && cell[i][ptr] >= dp[!(i % 2)][ptr2].second)
			{
				ptr--;
			}

			if (ptr > 0 && cell[i][ptr] < dp[!(i % 2)][ptr2].second)
			{
				ptr++;
			}
			*/

			if (dp[!(i % 2)][ptr2].first + cell[i].size() - ptr< min)
			{
				min = dp[!(i % 2)][ptr2].first + cell[i].size() - ptr;
			}

			dp[i % 2].insert(dp[i % 2].begin(), pair<long long, long long>(dp[!(i % 2)][ptr2].first + 1, dp[!(i % 2)][ptr2].second));

			if (ptr2 == 0)
			{
				break;
			}

			pre = ptr2;
		}

		dp[!(i % 2)].clear();
	}

	printf("%I64d\n", min);

	return 0;
}