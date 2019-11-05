#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool func(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second < b.second;
}

bool func2(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
{
	return a.second.second<b.second.second || a.second.second == b.second.second&&a.second.first>b.second.first;
}

int main()
{
	vector<pair<int, int>> dist, order;
	vector<pair<int, pair<int, int>>> dist2;
	bool *change;
	int n, m;
	int i;
	int input, input2;
	int last;
	int off = 0;
	int cnt = 0;

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	change = new bool[n + 1];

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		dist.push_back(pair<int, int>(input, n - i - 1));

		dist2.push_back(pair<int, pair<int, int>>(input, pair<int, int>(n - i - 1, n - i - 1)));

		order.push_back(pair<int, int>(i, input));

		change[i + 1] = false;

		last = input;
	}

	sort(order.begin(), order.end(), func);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &input, &input2);

		if (input2 == last)
		{
			change[input] = true;
		}

		dist[order[input - 1].first].second--;
		dist2[order[input - 1].first].second.second--;
	}

	sort(dist.begin(), dist.end(), func);
	sort(dist2.begin(), dist2.end(), func2);

	for (i = 0; i < n; i++)
	{
		/*
		if (dist[i].first == last)
		{
			off++;

			continue;
		}

		if (dist[i].second + off > i)
		{
			break;
		}

		if (change[dist[i].first])
		{
			cnt++;
		}

		else
		{
			off++;
		}
		*/

		if (dist2[i].first == last)
		{
			off++;

			continue;
		}

		/*
		if (dist2[i].second.second + off > i)
		{
			break;
		}
		*/

		if (change[dist2[i].first] && (dist2[i].second.first - cnt + off - 1 <= i || dist2[i].second.first==1))
		{
			cnt++;
		}

		else
		{
			off++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}