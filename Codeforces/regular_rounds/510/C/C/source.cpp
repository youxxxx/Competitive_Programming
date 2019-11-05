#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

bool func(pair<int,int> &a, pair<int, int> &b)
{
	return abs(a.first) < abs(b.first);
}

int main()
{
	vector<pair<int, int>> arr;
	vector<int> zindex;
	int n, i, j, ptr;
	int input, sign = 1;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(pair<int, int>(input, i + 1));

		if (input)
		{
			sign *= input / abs(input);
		}
	}

	sort(arr.begin(), arr.end(), func);

	i = -1;

	while (++i<n && !(arr[i].first))
	{
		zindex.push_back(arr[i].first);
	}

	if (i == n)
	{
		for (j = 0; j < n - 1; j++)
		{
			printf("1 %d %d\n", arr[j].second, arr[j + 1].second);
		}
	}

	else if (i == n - 1)
	{
		if (sign == 1)
		{
			for (j = 0; j < n - 2; j++)
			{
				printf("1 %d %d\n", arr[j].second, arr[j + 1].second);
			}

			printf("2 %d\n", arr[n-1].second);
		}

		else
		{
			for (j = 0; j < n - 1; j++)
			{
				printf("1 %d %d\n", arr[j].second, arr[j + 1].second);
			}
		}
	}

	else
	{
		if (sign == 1)
		{
			for (j = 0; j < i - 1; j++)
			{
				printf("1 %d %d\n", arr[j].second, arr[j + 1].second);
			}

			if (i > 0)
			{
				printf("2 %d\n", arr[i - 1].second);
			}

			for (j = i; j < n - 1; j++)
			{
				printf("1 %d %d\n", arr[j].second, arr[j + 1].second);
			}
		}

		else
		{
			for (j = 0; j < i - 1; j++)
			{
				printf("1 %d %d\n", arr[j].second, arr[j + 1].second);
			}

			ptr = i - 1;

			while (++ptr < n&&arr[ptr].first > 0);

			if (ptr == 0)
			{
				printf("2 %d\n", arr[0].second);

				arr.erase(arr.begin());

				for (j = 0; j < n - 2; j++)
				{
					printf("1 %d %d\n", arr[j].second, arr[j + 1].second);
				}
			}

			else
			{
				if (i > 0)
				{
					printf("1 %d %d\n", arr[i - 1].second, arr[ptr].second);
				}

				printf("2 %d\n", arr[ptr].second);

				arr.erase(arr.begin() + ptr);

				for (j = i; j < n - 2; j++)
				{
					printf("1 %d %d\n", arr[j].second, arr[j + 1].second);
				}
			}
		}
	}


	return 0;
}