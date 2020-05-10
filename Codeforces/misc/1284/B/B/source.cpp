#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

int main()
{
	long long n;
	vector<long long> lmax, lmin;
	long long sol = 0;

	scanf("%lld", &n);

	for (long long i = 0; i < n; i++)
	{
		long long k;
		long long curmin = 1000001, curmax = 0;
		bool asc = false;

		scanf("%lld", &k);

		for (long long j = 0; j < k; j++)
		{
			long long input;

			scanf("%lld", &input);

			if (input < curmin)
			{
				curmin = input;
			}

			else if (input > curmin)
			{
				asc = true;
			}

			if (input > curmax)
			{
				curmax = input;
			}
		}

		if (asc)
		{
			sol += n;
		}

		else
		{
			lmin.push_back(curmin);

			lmax.push_back(curmax);
		}
	}

	sol += lmin.size()*(n - lmax.size());

	sort(lmax.begin(), lmax.end());

	for (long long i = 0; i < lmin.size(); i++)
	{
		vector<long long>::iterator ret;

		ret = upper_bound(lmax.begin(), lmax.end(), lmin[i]);

		sol += lmax.size() - (ret - lmax.begin());
	}

	printf("%lld\n", sol);

	return 0;
}