#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		pair<int, int> arr[100001];

		for (int i = 0; i < n; i++)
		{
			int t, x;

			scanf("%d %d", &t, &x);

			arr[i] = { t,x };
		}

		int prev = 0;
		int target = 0;
		int stop = 0;
		int sol = 0;
		int dir = 0;

		for (int i = 0; i < n; i++)
		{
			if (stop <= arr[i].first)
			{
				const int dist = abs(arr[i].second - target);

				if (i == n - 1 || dist <= arr[i + 1].first - arr[i].first)
				{
					sol++;
				}

				if (arr[i].second == target)
				{
					dir = 0;
				}

				else
				{
					dir = (arr[i].second - target) / abs(arr[i].second - target);
				}

				prev = target;

				if (dir && i != n - 1)
				{
					prev = target + dir*(arr[i + 1].first - arr[i].first);
				}

				stop = arr[i].first + dist;

				target = arr[i].second;
			}
			
			/*
			else if (i == n - 1 || stop < arr[i + 1].first)
			{
				const int dist = abs(arr[i].second - target);

				if (i == n - 1)
				{
					sol++;
				}

				else if ((prev <= arr[i].second && arr[i].second <= target) || (prev >= arr[i].second && arr[i].second >= target) || dist <= arr[i + 1].first - stop)
				{
					sol++;
				}

				if (arr[i].second == target)
				{
					dir = 0;
				}

				else
				{
					dir = (arr[i].second - target) / abs(arr[i].second - target);
				}

				prev = target;

				if (dir && i != n - 1)
				{
					prev = target + dir*(arr[i + 1].first - stop);
				}

				stop += dist;

				target = arr[i].second;
			}
			*/

			else
			{
				if (i == n - 1)
				{
					if ((prev <= arr[i].second && arr[i].second <= target) || (prev >= arr[i].second && arr[i].second >= target))
					{
						sol++;
					}
				}

				else
				{
					int temp;

					if (stop <= arr[i + 1].first)
					{
						temp = target;
					}

					else
					{
						temp = prev + dir*(arr[i + 1].first - arr[i].first);
					}

					if ((prev <= arr[i].second && arr[i].second <= temp) || (prev >= arr[i].second && arr[i].second >= temp))
					{
						sol++;
					}

					prev = temp;
				}
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}