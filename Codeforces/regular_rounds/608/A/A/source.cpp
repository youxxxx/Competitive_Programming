#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	long long arr[6];

	for (long long i = 0; i < 6; i++)
	{
		scanf("%lld", &arr[i]);
	}

	long long lmax;

	lmax = arr[0] < arr[3] ? arr[0] : arr[3];

	long long sol = 0;

	for (long long i = 0; i <= lmax; i++)
	{
		long long val;

		val = arr[4] * i;

		long long lmin;

		lmin = arr[1] < arr[2] ? arr[1] : arr[2];

		if (arr[3] - i < lmin)
		{
			lmin = arr[3] - i;
		}

		val += lmin*arr[5];

		if (val > sol)
		{
			sol = val;
		}
	}

	printf("%lld\n", sol);

	return 0;
}