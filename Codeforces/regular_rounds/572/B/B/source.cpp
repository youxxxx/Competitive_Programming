#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int i;
	int n;
	vector<long long> arr;
	long long input;
	long long temp;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);
	}

	if (n == 3)
	{
		for (i = 0; i < n; i++)
		{
			if (arr[i] + arr[(i + 1) % 3] <= arr[(i + 2) % 3])
			{
				printf("NO\n");

				return 0;
			}
		}

		printf("YES\n");

		for (i = 0; i < n; i++)
		{
			printf("%lld ", arr[i]);
		}

		return 0;
	}

	sort(arr.begin(), arr.end());

	
		temp = arr[n - 2];
		arr[n - 2] = arr[n - 1];
		arr[n - 1] = temp;

	for (i = 1; i < n - 1; i++)
	{
		if (arr[i] >= arr[i - 1] + arr[i + 1])
		{
			printf("NO\n");

			return 0;
		}
	}

	printf("YES\n");

	for (i = 0; i < n; i++)
	{
		printf("%lld ", arr[i]);
	}

	return 0;
}