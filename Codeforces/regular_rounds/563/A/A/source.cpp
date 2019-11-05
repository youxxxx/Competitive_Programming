#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	vector<long long> arr, arr2;
	long long input;
	long long temp;
	int i, j, k;
	long long base;
	long long sum1 = 0, sum2 = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);

		sum1 += arr[i];
	}

	sort(arr.begin(), arr.end());

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr2.push_back(input);

		sum2 += arr2[i];
	}

	if (sum1 != sum2)
	{
		for (i = 0; i < n; i++)
		{
			printf("%lld ", arr[i]);
		}

		for (i = 0; i < n; i++)
		{
			printf("%lld ", arr2[i]);
		}

		return 0;
	}

	sort(arr2.begin(), arr2.end());

	j = 0;

	if (arr[0] != arr2[0])
	{
		temp = arr[0];
		arr[0] = arr2[0];
		arr2[0] = temp;

		for (i = 0; i < n; i++)
		{
			printf("%lld ", arr[i]);
		}

		for (i = 0; i < n; i++)
		{
			printf("%lld ", arr2[i]);
		}

		return 0;
	}

	base = arr[0];

	for (i = 1; i < n; i++)
	{
		if (arr[i] != base)
		{
			break;
		}
	}

	if (i != n)
	{
		temp = arr[i];
		arr[i] = arr2[0];
		arr2[0] = temp;

		for (i = 0; i < n; i++)
		{
			printf("%lld ", arr[i]);
		}

		for (i = 0; i < n; i++)
		{
			printf("%lld ", arr2[i]);
		}

		return 0;
	}

	base = arr2[0];

	for (i = 1; i < n; i++)
	{
		if (arr2[i] != base)
		{
			break;
		}
	}

	if (i != n)
	{
		temp = arr[0];
		arr[0] = arr2[i];
		arr2[i] = temp;

		for (i = 0; i < n; i++)
		{
			printf("%lld ", arr[i]);
		}

		for (i = 0; i < n; i++)
		{
			printf("%lld ", arr2[i]);
		}

		return 0;
	}

	printf("-1\n");

	return 0;
}