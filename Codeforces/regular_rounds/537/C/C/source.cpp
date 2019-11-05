#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

long long n, k, a, b;
long long input;
vector<long long> arr;
long long half;
long long val;
long long minval;

long long dnc(long long lidx, long long uidx, long long lb, long long ub)
{
	long long next;
	long long lcost, rcost;
	long long lcand, rcand;
	vector<long long>::iterator it;

	if (ub - lb == 1)
	{
		return b*(uidx - lidx);
	}

	next = (lb + ub) / 2;

	it = lower_bound(arr.begin() + lidx, arr.begin() + uidx, next);

	if (it == arr.begin() + lidx || it == arr.begin() + uidx)
	{
		if (it == arr.begin() + lidx)
		{
			lcand = lcost = a;
			rcost = b*(uidx - lidx)*(next - lb);

			rcand = dnc(lidx, uidx, next, ub);
		}

		else
		{
			lcost = b*(uidx - lidx)*(next - lb);
			rcand = rcost = a;

			lcand = dnc(lidx, uidx, lb, next);
		}
	}

	else
	{
		lcost = (it - (arr.begin() + lidx))*(next - lb)*b;

		rcost = (arr.begin() + uidx - it)*(next - lb)*b;

		lcand = dnc(lidx, it - arr.begin(), lb, next);
		rcand = dnc(it - arr.begin(), uidx, next, ub);
	}

	if (lcand < lcost)
	{
		lcost = lcand;
	}

	if (rcand < rcost)
	{
		rcost = rcand;
	}

	return lcost + rcost;
}

int main()
{
	long long i,j;
	long long pw;
	long long sol;

	scanf("%I64d %I64d %I64d %I64d", &n, &k, &a, &b);

	for (i = 0; i < k; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input - 1);
	}

	sort(arr.begin(), arr.end());

	pw = (long long)pow((double)2.0, (double)n);

	sol = dnc(0, k, 0, pw);

	if (k*pw*b < sol)
	{
		sol = k*pw*b;
	}

	printf("%I64d\n", sol);

	return 0;
}