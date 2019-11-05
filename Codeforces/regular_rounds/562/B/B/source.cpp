#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<functional>

using namespace std;

int main()
{
	int n, m;
	int i;
	int h1, h2;
	int hcnt;
	int input1, input2;
	vector<pair<int, int>> arr;
	vector<int> idx;
	int hold[2];

	scanf("%d %d", &n, &m);

	scanf("%d %d", &h1, &h2);

	arr.push_back(pair<int, int>(h1, h2));

	for (i = 1; i < m; i++)
	{
		scanf("%d %d", &input1, &input2);

		arr.push_back(pair<int, int>(input1, input2));

		if (h1 != arr[i].first&&h1 != arr[i].second)
		{
			idx.push_back(i);
		}
	}

	if (idx.empty())
	{
		printf("YES\n");

		return 0;
	}

	hold[0] = arr[idx[0]].first;
	hold[1] = arr[idx[0]].second;
	hcnt = 2;

	if (hold[0] == h1)
	{
		hold[0] = hold[1];
		hcnt = 1;
	}

	else if (hold[1] == h1)
	{
		hcnt = 1;
	}

	for (i = 1; i < idx.size(); i++)
	{
		if (hcnt == 2)
		{
			if (hold[0] != arr[idx[i]].first&&hold[0] != arr[idx[i]].second)
			{
				if (hold[1] != arr[idx[i]].first&&hold[1] != arr[idx[i]].second)
				{
					hcnt = 0;

					break;
				}

				else
				{
					hcnt = 1;

					hold[0] = hold[1];
				}
			}

			else
			{
				if (hold[1] != arr[idx[i]].first&&hold[1] != arr[idx[i]].second)
				{
					hcnt = 1;
				}
			}
		}

		else if (hcnt == 1)
		{
			if (hold[0] != arr[idx[i]].first&&hold[0] != arr[idx[i]].second)
			{
				hcnt = 0;

				break;
			}
		}
	}

	if (hcnt != 0)
	{
		printf("YES\n");

		return 0;
	}

	idx.clear();

	for (i = 1; i < m; i++)
	{
		if (h2 != arr[i].first&&h2 != arr[i].second)
		{
			idx.push_back(i);
		}
	}

	if (idx.empty())
	{
		printf("YES\n");

		return 0;
	}

	hold[0] = arr[idx[0]].first;
	hold[1] = arr[idx[0]].second;
	hcnt = 2;

	if (hold[0] == h2)
	{
		hold[0] = hold[1];
		hcnt = 1;
	}

	else if (hold[1] == h2)
	{
		hcnt = 1;
	}

	for (i = 1; i < idx.size(); i++)
	{
		if (hcnt == 2)
		{
			if (hold[0] != arr[idx[i]].first&&hold[0] != arr[idx[i]].second)
			{
				if (hold[1] != arr[idx[i]].first&&hold[1] != arr[idx[i]].second)
				{
					hcnt = 0;

					break;
				}

				else
				{
					hcnt = 1;

					hold[0] = hold[1];
				}
			}

			else
			{
				if (hold[1] != arr[idx[i]].first&&hold[1] != arr[idx[i]].second)
				{
					hcnt = 1;
				}
			}
		}

		else if (hcnt == 1)
		{
			if (hold[0] != arr[idx[i]].first&&hold[0] != arr[idx[i]].second)
			{
				hcnt = 0;

				break;
			}
		}
	}

	if (hcnt != 0)
	{
		printf("YES\n");

		return 0;
	}

	printf("NO\n");

	return 0;
}