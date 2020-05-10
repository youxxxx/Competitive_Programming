#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long n;
		vector<long long> arr;
		long long s;

		scanf("%lld %lld", &n, &s);

		long long sum = 0;

		for (long long i = 0; i < n; i++)
		{
			long long input;

			scanf("%lld", &input);

			arr.push_back(input);

			sum += input;
		}

		if (sum <= s)
		{
			printf("0\n");

			continue;
		}

		long long cur = 0;
		long long lmax = 0;
		long long midx;

		for (long long i = 0; i < n; i++)
		{
			if (arr[i] > lmax)
			{
				lmax = arr[i];

				midx = i;
			}

			cur += arr[i];

			if (cur > s)
			{
				break;
			}
		}

		printf("%lld\n", midx + 1);
	}

	return 0;
}