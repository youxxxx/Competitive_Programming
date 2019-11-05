#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long l, n;
	long long fptr, bptr;
	long long i;
	long long cur = 0;
	long long sum = 0;
	long long input;
	vector<long long> arr;
	long long fpath, bpath;

	scanf("%lld %lld", &l, &n);

	fptr = 0;
	bptr = n - 1;

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		if (cur > arr[fptr])
		{
			fpath = (l - cur) + arr[fptr];
		}

		else
		{
			fpath = arr[fptr] - cur;
		}

		if (cur < arr[bptr])
		{
			bpath = cur + (l - arr[bptr]);
		}

		else
		{
			bpath = cur - arr[bptr];
		}

		if (fpath>bpath)
		{
			sum += fpath;

			cur = arr[fptr];

			fptr++;
		}

		else
		{
			sum += bpath;

			cur = arr[bptr];

			bptr--;
		}
	}
	
	printf("%lld\n", sum);

	return 0;
}