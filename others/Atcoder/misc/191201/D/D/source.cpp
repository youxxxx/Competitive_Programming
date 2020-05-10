#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	char input[30001];
	string str;
	vector<int> pos[10];

	scanf("%s", input);

	str = input;

	for (int i = 0; i < n; i++)
	{
		pos[str[i] - '0'].push_back(i);
	}

	int sol = 0;

	for (int i = 0; i < 10; i++)
	{
		if (pos[i].empty())
		{
			continue;
		}

		for (int j = 0; j < 10; j++)
		{
			if (pos[j].empty())
			{
				continue;
			}

			for (int k = 0; k < 10; k++)
			{
				if (pos[k].empty())
				{
					continue;
				}

				int lb, ub;

				lb = pos[i].front();
				ub = pos[k].back();

				if (lb == ub)
				{
					continue;
				}

				vector<int>::iterator ret;

				ret = upper_bound(pos[j].begin(), pos[j].end(), lb);

				if (ret == pos[j].end() || *ret >= ub)
				{
					continue;
				}

				sol++;
			}
		}
	}

	printf("%d\n", sol);

	return 0;
}