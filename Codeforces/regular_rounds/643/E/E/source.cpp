#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	long long n, a, r, m;
	
	scanf("%lld %lld %lld %lld", &n, &a, &r, &m);

	vector<long long> arr;
	long long sum = 0;

	for (long long i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		arr.push_back(input);

		sum += input;
	}

	/*
	if (m <= a + r)
	{
		long long sol;

		const long long q = sum / n;
		long long rem = sum%n;

		long long cnt = 0;

		for (long long i = 0; i < n; i++)
		{
			if (arr[i] < q)
			{
				cnt += q - arr[i];
			}
		}

		sol = cnt*m + rem*r;

		long long cand;
		
		cnt = 0;

		for (long long i = 0; i < n; i++)
		{
			if (arr[i] > q + 1)
			{
				cnt += arr[i] - (q + 1);
			}
		}

		cand = cnt*m + ((q + 1)*n - sum) % a;

		if (cand < sol)
		{
			sol = cand;
		}

		printf("%lld\n", sol);
	}

	else
	{
		sort(arr.begin(), arr.end());
		long long subt = 0, add = 0;

		for (long long i = n - 1; i >= 1; i--)
		{
			subt += arr[i];
		}

		long long prev = 0;

		long long sol = 999999999999999999;

		for (long long i = 0; i < n; i++)
		{
			subt -= (n - i)*(arr[i] - prev);
			add += i*(arr[i] - prev);

			const long long cand = add*a + subt*r;

			if (cand < sol)
			{
				sol = cand;
			}

			prev = arr[i];
		}

		printf("%lld\n", sol);
	}
	*/

	sort(arr.begin(), arr.end());

	long long sol = 999999999999999999;

	long long cand;
	
	const long long q = sum / n;
	long long rem = sum%n;

	long long cnt = 0;

	for (long long i = 0; i < n; i++)
	{
		if (arr[i] < q)
		{
			cnt += q - arr[i];
		}
	}

	cand = cnt*m + rem*r;

	if (cand < sol)
	{
		sol = cand;
	}

	cnt = 0;

	for (long long i = 0; i < n; i++)
	{
		if (arr[i] > q + 1)
		{
			cnt += arr[i] - (q + 1);
		}
	}

	cand = cnt*m + ((q + 1)*n - sum) * a;

	if (cand < sol)
	{
		sol = cand;
	}

	long long subt = 0, add = 0;

	for (long long i = n - 1; i >= 0; i--)
	{
		subt += arr[i];
	}

	long long prev = 0;

	for (long long i = 0; i < n; i++)
	{
		subt -= (n - i)*(arr[i] - prev);
		add += i*(arr[i] - prev);

		long long cand;

		if (a + r <= m)
		{
			cand = add*a + subt * r;
		}

		else
		{
			long long ma, mr, mm;

			mm = add < subt ? add : subt;

			ma = add - mm;
			mr = subt - mm;

			cand = ma*a + mr*r + mm*m;
		}

		if (cand < sol)
		{
			sol = cand;
		}

		prev = arr[i];
	}

	printf("%lld\n", sol);

	return 0;
}