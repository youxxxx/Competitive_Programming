#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n, x, y;
	vector<int> arr;
	int input;
	int i, j;
	int lb, ub;

	scanf("%d %d %d", &n, &x, &y);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		lb = 0 > i - x ? 0 : i - x;
		ub = n - 1 < i + y ? n - 1 : i + y;

		for (j = lb; j < i; j++)
		{
			if (arr[j] <= arr[i])
			{
				break;
			}
		}

		if (j != i)
		{
			continue;
		}

		for (j = i + 1; j <= ub; j++)
		{
			if (arr[j] <= arr[i])
			{
				break;
			}
		}

		if (j == ub + 1)
		{
			printf("%d\n", i + 1);

			return 0;
		}
	}

	return 0;
}