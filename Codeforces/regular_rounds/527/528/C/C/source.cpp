#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool func(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first < b.first || a.first == b.first && a.second < b.second;
}

int main()
{
	int i;
	vector<pair<int, int>> coord;
	vector<pair<int, int>> sol;
	int input1, input2;
	int lmin, lmax;
	int start;

	for (i = 0; i < 3; i++)
	{
		scanf("%d %d", &input1, &input2);

		coord.push_back(pair<int, int>(input1, input2));
	}

	sort(coord.begin(), coord.end(), func);

	sol.push_back(coord[0]);

	for (i = coord[0].first + 1; i <= coord[1].first; i++)
	{
		sol.push_back(pair<int, int>(i, coord[0].second));
	}

	if (coord[1].second < coord[0].second)
	{
		for (i = coord[0].second - 1; i >= coord[1].second; i--)
		{
			sol.push_back(pair<int, int>(coord[1].first, i));
		}
	}

	else if (coord[1].second > coord[0].second)
	{
		for (i = coord[0].second + 1; i <= coord[1].second; i++)
		{
			sol.push_back(pair<int, int>(coord[1].first, i));
		}
	}

	for (i = coord[1].first + 1; i <= coord[2].first; i++)
	{
		sol.push_back(pair<int, int>(i, coord[2].second));
	}

	lmin = (coord[0].second < coord[1].second) ? coord[0].second : coord[1].second;
	lmax = (coord[0].second > coord[1].second) ? coord[0].second : coord[1].second;

	if (coord[2].second < lmin)
	{
		for (i = coord[2].second; i < lmin; i++)
		{
			sol.push_back(pair<int, int>(coord[1].first, i));
		}
	}

	else if (coord[2].second > lmax)
	{
		for (i = coord[2].second; i > lmax; i--)
		{
			sol.push_back(pair<int, int>(coord[1].first, i));
		}
	}

	printf("%d\n", sol.size());

	for (i = 0; i < sol.size(); i++)
	{
		printf("%d %d\n", sol[i].first, sol[i].second);
	}

	return 0;
}