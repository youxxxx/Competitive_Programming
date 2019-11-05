#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

bool func(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
{
	return a.first.first < b.first.first || a.first.first == b.first.first&&a.first.second < b.first.second;
}

bool func2(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
{
	return a.second < b.second;
}

int main()
{
	int n, m;
	vector<pair<pair<int, int>, int>> city;
	vector<pair<pair<int, int>, int>> id;
	int i;
	int input1, input2;
	int cnt = 1;


	scanf("%d %d", &n, &m);

	for(i=0;i<m;i++)
	{
		scanf("%d %d", &input1, &input2);

		city.push_back(pair<pair<int, int>, int>(pair<int, int>(input1, input2), i + 1));
	}

	sort(city.begin(), city.end(), func);

	id.push_back(pair<pair<int, int>, int>(pair<int, int>(city[0].first.first, 1), city[0].second));

	for (i = 1; i < m; i++)
	{
		if (city[i].first.first != city[i - 1].first.first)
		{
			cnt = 1;
		}

		else
		{
			cnt++;
		}

		id.push_back(pair<pair<int, int>, int>(pair<int, int>(city[i].first.first, cnt), city[i].second));
	}

	sort(id.begin(), id.end(), func2);

	for (i = 0; i < m; i++)
	{
		printf("%06d%06d\n", id[i].first.first, id[i].first.second);
	}

	return 0;
}