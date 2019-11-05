#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> arr;
	vector<pair<int, pair<int, int>>> moves;
	pair<int, pair<int, int>> cur;
	int input;
	int i, j;
	int lmax = 0, mval;
	int sidx = -1;
	int *cnt;
	int prev;

	scanf("%d", &n);

	cnt = new int[200001];

	for (i = 0; i <= 200000; i++)
	{
		cnt[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		if (++cnt[arr[i]] > lmax)
		{
			mval = arr[i];

			lmax = cnt[arr[i]];
		}
	}

	while (++sidx < n&&arr[sidx] != mval);

	for (i = sidx - 1; i >= 0; i--)
	{
		if (arr[i] < mval)
		{
			cur.first = 1;
		}

		else
		{
			cur.first = 2;
		}

		cur.second.first = i;
		cur.second.second = i + 1;

		moves.push_back(cur);
	}

	prev = sidx;

	for (i = sidx + 1; i < n; i++)
	{
		if (arr[i] == mval)
		{
			for (j = prev; j < i - 1; j++)
			{
				if (arr[j + 1] < mval)
				{
					cur.first = 1;
				}

				else
				{
					cur.first = 2;
				}

				cur.second.first = j + 1;
				cur.second.second = j;

				moves.push_back(cur);
			}

			prev = i;
		}
	}

	for (j = prev; j < n - 1; j++)
	{
		if (arr[j + 1] < mval)
		{
			cur.first = 1;
		}

		else
		{
			cur.first = 2;
		}

		cur.second.first = j + 1;
		cur.second.second = j;

		moves.push_back(cur);
	}

	printf("%d\n", moves.size());

	for (i = 0; i < moves.size(); i++)
	{
		printf("%d %d %d\n", moves[i].first, moves[i].second.first + 1, moves[i].second.second + 1);
	}

	return 0;
}