#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool func(pair<int, int> &a, pair<int, int> &b)
{
	return a.first < b.first || a.first == b.first&&a.second < b.second;
}

int main()
{
	vector<int> sol;
	vector<pair<int, int>> seg;
	int n, m, i, j;
	int input1, input2;
	int max;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &input1, &input2);

		seg.push_back(pair<int, int>(input1, input2));
	}

	sort(seg.begin(), seg.end());

	for (i = 1; i < seg[0].first; i++)
	{
		sol.push_back(i);
	}

	max = seg[0].second;

	for (i = 1; i < seg.size(); i++)
	{
		if (seg[i].first > max)
		{
			for (j = max + 1; j < seg[i].first; j++)
			{
				sol.push_back(j);
			}
		}

		if (max < seg[i].second)
		{
			max = seg[i].second;
		}
	}

	for (i = max + 1; i <= m; i++)
	{
		sol.push_back(i);
	}

	printf("%d\n", sol.size());

	for (i = 0; i < sol.size(); i++)
	{
		printf("%d ", sol[i]);
	}

	return 0;
}