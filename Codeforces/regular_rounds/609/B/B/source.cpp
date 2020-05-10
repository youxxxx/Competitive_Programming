#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int n, m;
	map<int, int> list[2];

	scanf("%d %d", &n, &m);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			map<int, int>::iterator ret;

			int input;

			scanf("%d", &input);

			ret = list[i].find(input);

			if (ret == list[i].end())
			{
				list[i][input] = 1;
			}

			else
			{
				ret->second++;
			}
		}
	}

	vector<pair<int, int>> p[2];

	for (int i = 0; i < 2; i++)
	{
		map<int, int>::iterator it;

		for (it = list[i].begin(); it != list[i].end(); it++)
		{
			p[i].push_back({ it->first,it->second });
		}
	}

	int lmin = 2000000000;

	if (p[0].size() == 1)
	{
		printf("%d\n", (p[1][0].first + m - p[0][0].first) % m);

		return 0;
	}

	for (int i = 0; i < p[0].size(); i++)
	{
		int diff;

		if (p[0][0].second != p[1][i].second)
		{
			continue;
		}

		diff = (p[1][i].first + m - p[0][0].first) % m;

		bool valid = true;

		for (int j = 1; j < p[0].size(); j++)
		{
			if ((p[1][(i + j) % p[0].size()].first + m - p[0][j].first) % m != diff || p[0][j].second != p[1][(i+j)%p[0].size()].second)
			{
				valid = false;

				break;
			}
		}

		if (valid&&diff < lmin)
		{
			lmin = diff;
		}
	}

	printf("%d\n", lmin);

	return 0;
}