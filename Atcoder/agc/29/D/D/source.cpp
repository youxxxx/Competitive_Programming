#include<cstdio>
#include<vector>
#include<set>

using namespace std;

int main()
{
	int h, w, n;
	int cnt;
	vector<pair<int,int>> min;
	int i, j;
	int input1, input2;
	int curx = 1, cury = 1;
	int newx, newy;

	scanf("%d %d %d", &h, &w, &n);

	for (i = 0; i <= h; i++)
	{
		min.push_back(pair<int, int>(i, w + 1));
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &input1, &input2);

		if (input2 < min[input1].second)
		{
			min[input1].second = input2;
		}
	}

	for (i = h; i >= 0; i--)
	{
		if (min[i].second > i)
		{
			min.erase(min.begin() + i);
		}
	}

	for (i = 0; i < min.size(); i++)
	{
		newx = min[i].first;
		newy = min[i].second;

		if (newx - curx > newy - cury)
		{
			printf("%d\n", newx - 1);

			return 0;
		}

		else if (newx - curx == newy - cury)
		{
			curx = newx;
			cury = newy - 1;
		}

		else
		{
			cury += newx - curx;

			if (cury >= w)
			{
				cury = w;
			}

			curx = newx;
		}
	}

	printf("%d\n", h);

	return 0;
}