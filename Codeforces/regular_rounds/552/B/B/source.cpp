#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	int n;
	int i;
	int input;
	vector<int> arr;
	int low, mid = -1, high;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	if (arr[0] == arr[n - 1])
	{
		printf("0\n");

		return 0;
	}

	low = arr[0];
	high = arr[n - 1];

	for (i = 1; i < n - 1; i++)
	{
		if (arr[i] != low&&arr[i] != high)
		{
			if (mid != -1 && arr[i] != mid)
			{
				printf("-1\n");

				return 0;
			}

			mid = arr[i];
		}
	}

	if (mid == -1)
	{
		if (!((high - low) % 2))
		{
			printf("%d\n", (high - low) / 2);
		}

		else
		{
			printf("%d\n", (high - low));
		}
	}

	else
	{
		if (!((high - low) % 2) && mid == (high + low) / 2)
		{
			printf("%d\n", (high - low) / 2);
		}

		else
		{
			printf("-1\n");
		}
	}

	return 0;
}