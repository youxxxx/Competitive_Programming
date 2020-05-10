#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long n;
	vector<long long> arr;
	long long cnt = 0;

	scanf("%lld", &n);

	for (long long i = 0; i < n; i++)
	{
		long long input;
		
		scanf("%lld", &input);

		if (input)
		{
			cnt++;

			arr.push_back(i);
		}
	}

	if (cnt == 1)
	{
		printf("-1\n");

		return 0;
	}

	long long ub = (long long)sqrt((double)cnt);

	vector<long long> divd;

	long long sol = 100000000000;

	for (long long i = 2; i <= ub; i++)
	{
		long long cand = 0;
		long long size;

		if (!(cnt%i))
		{
			long long chunk;

			chunk = cnt / i;

			for (long long j = 0; j < chunk; j++)
			{
				for (long long k = 0; k < i; k++)
				{
					cand += abs(arr[j*i + k] - arr[j*i + (i / 2)]);
				}
			}

			if (cand < sol)
			{
				sol = cand;
			}

			divd.push_back(cnt / i);
		}
	}

	long long cand = 0;

	for (long long i = 0; i < divd.size(); i++)
	{
		long long chunk;

		chunk = cnt / divd[i];

		for (long long j = 0; j < chunk; j++)
		{
			for (long long k = 0; k < divd[i]; k++)
			{
				cand += abs(arr[j*divd[i] + k] - arr[j*divd[i] + (divd[i] / 2)]);
			}
		}

		if (cand < sol)
		{
			sol = cand;
		}
	}

	cand = 0;

	for (long long j = 0; j < cnt; j++)
	{
		cand += abs(arr[j] - arr[cnt / 2]);
	}

	if (cand < sol)
	{
		sol = cand;
	}

	printf("%lld\n", sol);

	return 0;
}