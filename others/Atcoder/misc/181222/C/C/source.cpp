#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

long long bsearch(long long div, long long pw, long long lb, long long ub)
{
	long long val;
	long long next;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	val = (long long)pow((double)pw, next);

	if (!(div%val))
	{
		return bsearch(div, pw, next, ub);
	}

	else
	{
		return bsearch(div, pw, lb, next);
	}
}

int main()
{
	vector<long long> prime;

	long long n, p;
	long long i, j;
	long long pw;
	bool isprime;
	long long sol = 1;
	long long psol;
	long long cur;
	long long root;

	scanf("%lld %lld", &n, &p);

	if (n == 1)
	{
		printf("%lld\n", p);

		return 0;
	}

	root = pow((double)p, 1.0 / (double)n) + 1;

	for (i = root; i > 1; i--)
	{
		if (!(p % (long long)pow((double)i,n)))
		{
			break;
		}
	}

	printf("%lld\n", i);

	return 0;

	/*	
	prime.push_back(2);

	if (!(p%2))
	{
		psol = bsearch(p, 2, 1, (long long)((log10((double)p) / log10(2.0)) + 1));

		p /= (long long)pow(2.0, psol);

		sol *= (long long)pow(2.0, psol / n);
	}

	for (i = 3; (long long)pow(i, n) <= p; i += 2)
	{
		isprime = true;

		for (j = 0; j < prime.size() && prime[j] * prime[j] <= i; j++)
		{
			if (!(i%prime[j]))
			{
				isprime = false;

				break;
			}
		}

		if (isprime)
		{
			prime.push_back(i);

			if (!(p%i))
			{
				psol = bsearch(p, i, 1, (long long)((log10((double)p) / log10((double)i)) + 1));

				p /= (long long)pow((double)i, psol);

				sol *= (long long)pow((double)i, psol / n);
			}
		}		
	}

	/*
	for (i = 0; i < prime.size(); i++)
	{
		cur = (long long)pow(prime[i], n);

		if (p < cur)
		{
			break;
		}

		if (!(p%cur))
		{
			psol = bsearch(p, cur, 1, (long long)((log10((double)p) / log10(cur)) + 1));

			sol *= (long long)pow((double)prime[i], psol);

			p /= (long long)pow((double)cur, psol);
		}
	}

	printf("%lld\n", sol);

	return 0;
	*/
}