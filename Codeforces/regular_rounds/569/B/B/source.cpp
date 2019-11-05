#define _USE_MATH_DEFINES

#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int i;
	vector<long long> arr;
	long long input;
	long long sign = 1;
	long long prod = 1;
	long long cand;
	bool zeroarr = true;
	long long pmax = 0, nmax = 0;
	int pidx = -1, nidx = -1;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);

		if (input != 0)
		{
			//sign *= (input / abs(input));

			sign *= -1;

			zeroarr = false;
		}

		else
		{
			sign *= -1;
		}
	}

	/*
	if (n % 2)
	{
		sign *= -1;
	}
	*/

	if (zeroarr)
	{
		if (n % 2)
		{
			for (i = 0; i < n; i++)
			{
				printf("0 ");
			}
		}

		else
		{
			for (i = 0; i < n; i++)
			{
				printf("-1 ");
			}
		}

		return 0;
	}

	if (sign == 1)
	{
		for (i = 0; i < n; i++)
		{
			if (arr[i] >= 0)
			{
				printf("%lld ", -arr[i] - 1);
			}

			else
			{
				printf("%lld ", arr[i]);
			}
		}

		return 0;
	}

	for (i = 0; i < n; i++)
	{
		cand = abs(arr[i]) + (arr[i] > 0);

		if (arr[i] != 0 && cand > pmax)
		{
			pmax = cand;

			pidx = i;
		}
	}

	for (i = 0; i < n; i++)
	{
		if (arr[i] == 0)
		{
			printf("-1 ");
		}

		else if (i == pidx)
		{
			if (arr[i] < 0)
			{
				printf("%lld ", -arr[i] - 1);
			}

			else
			{
				printf("%lld ", arr[i]);
			}
		}

		else
		{
			if (arr[i] > 0)
			{
				printf("%lld ", -arr[i] - 1);
			}

			else
			{
				printf("%lld ", arr[i]);
			}
		}
	}

	return 0;
}