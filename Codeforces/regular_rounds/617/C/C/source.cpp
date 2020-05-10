#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		map<pair<int, int>, vector<int>> list;
		vector<int> emp;

		int xcoord = 0, ycoord = 0;

		list[{0, 0}]=emp;

		list.begin()->second.push_back(0);

		char dummy;

		scanf("%c", &dummy);

		for (int i = 1; i <= n; i++)
		{
			char input;

			scanf("%c", &input);

			switch (input)
			{
			case 'L':
				xcoord--;
				break;
			case 'R':
				xcoord++;
				break;
			case 'U':
				ycoord--;
				break;
			case 'D':
				ycoord++;
				break;
			}

			map<pair<int, int>, vector<int>>::iterator ret;
			pair<map<pair<int, int>, vector<int>>::iterator, bool> res;

			ret = list.find({ xcoord,ycoord });

			if (ret == list.end())
			{
				res = list.insert({ { xcoord,ycoord },emp });

				ret = res.first;
			}

			ret->second.push_back(i);
		}

		int lmin = -1;
		pair<int, int> sol;

		for (map<pair<int, int>, vector<int>>::iterator it = list.begin(); it != list.end(); it++)
		{
			for (int i = 1; i < it->second.size(); i++)
			{
				if (lmin == -1 || it->second[i] - it->second[i - 1] < lmin)
				{
					lmin = it->second[i] - it->second[i - 1];

					sol = { it->second[i - 1] + 1,it->second[i] };
				}
			}
		}

		if (lmin == -1)
		{
			printf("-1\n");
		}

		else
		{
			printf("%d %d\n", sol.first, sol.second);
		}
	}

	return 0;
}