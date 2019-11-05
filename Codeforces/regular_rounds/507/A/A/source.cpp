#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, a[2], min;
	int i, input, sum = 0;
	vector<int> arr;

	scanf("%d %d %d", &n, &a[0], &a[1]);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	min = a[0];

	if (a[1] < min)
	{
		min = a[1];
	}

	for (i = 0; i < n / 2; i++)
	{
		if (arr[i] == 2 && arr[n - i - 1] == 2)
		{
			sum += min * 2;
		}

		else if (arr[i] == 2)
		{
			sum += a[arr[n - i - 1]];
		}

		else if (arr[n - i - 1] == 2)
		{
			sum += a[arr[i]];
		}

		else if (arr[i] != arr[n - i - 1])
		{
			printf("-1");

			return 0;
		}
	}

	if (n % 2 && arr[n/2] == 2)
	{
		sum += min;
	}

	printf("%d", sum);

	return 0;
}