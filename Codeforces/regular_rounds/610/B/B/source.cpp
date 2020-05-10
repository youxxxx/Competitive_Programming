#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

long long n, k;
long long p;
vector<long long> arr;
vector<long long> qacc[200001], racc;

long long bin_search(long long lb, long long ub, long long r)
{
	long long next;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	long long sum;

	sum = qacc[r][next] + racc[r];

	if (sum > p)
	{
		return bin_search(lb, next, r);
	}

	return bin_search(next, ub, r);
}

int main()
{
	int cases;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		scanf("%lld %lld %lld", &n, &p, &k);

		arr.clear(); 
		racc.clear();

		for (long long i = 0; i <= k; i++)
		{
			qacc[i].clear();
		}

		arr.push_back(0);

		for (long long i = 0; i < n; i++)
		{
			long long input;

			scanf("%lld", &input);

			arr.push_back(input);
		}

		sort(arr.begin(), arr.end());

		long long acc = 0;
		
		for (long long i = 0; i < k; i++)
		{
			acc += arr[i];

			racc.push_back(acc);
		}

		for (long long i = 0; i < k; i++)
		{
			acc = 0;

			qacc[i].push_back(acc);

			for (long long j = i + k; j <= n; j += k)
			{
				acc += arr[j];

				qacc[i].push_back(acc);
			}
		}

		long long lmax = 0;

		for (long long i = 0; i < k; i++)
		{
			long long cand;
			long long ub;

			ub = n / k;

			if (ub*k + i > n)
			{
				ub--;
			}

			if (ub*k + i <= 0)
			{
				ub = 0;
			}

			cand = bin_search(-1, ub + 1, i);

			if (cand!=-1 && cand * k + i > lmax)
			{
				lmax = cand * k + i;
			}
		}

		printf("%lld\n", lmax);
	}

	return 0;
}