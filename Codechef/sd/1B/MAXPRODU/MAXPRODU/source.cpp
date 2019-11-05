#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

long long rec(vector<long long> &sol, long long rem, long long togo)
{
	long long cand;
	long long min;
	double real, tg, r;
	//double a, b, c;

	if (togo == 1)
	{
		sol.push_back(rem);

		return rem;
	}

	else if (togo == 2)
	{
		cand = rem / 2 + 1;

		sol.push_back(cand);

		//sol.push_back(rem - cand - 1);

		//rec(sol, rem - cand - 1, togo - 1);

		return cand;
	}

	else
	{
		//cand = (long long)sqrt((double)rem * 2.0);
		
		/*
		min = togo - 1;

		if (cand - 1 < min)
		{
			min = cand - 1;
		}

		while (min*(min + 1) / 2 > rem - cand)
		{
			cand--;
		}

		//if (min*(min + 1) / 2 < rem - cand)// (&& ((togo - 1)*(cand - 1 + cand - togo) / 2) < rem - cand)
		while ((togo - 1)*(cand + cand - togo) / 2 < rem - cand)
		{
			cand++;
		}
		*/

		//min = togo - 1;

		//((cand - 1) + (cand - (togo - 1)))*(togo - 1) / 2 >= rem - cand

		//(2*cand-togo)(togo-1)/2>=rem-cand
		//(2*cand*(togo-1) -togo(togo-1))/2>=rem-cand
		//((2*togo-2)*cand -togo(togo-1)) - 2*rem + 2*cand >=0
		//(2 * togo - 2 + 2)cand >= (togo^2-togo+2*rem)
		//cand >=(togo^2-togo+2*rem)/2*togo

		tg = (double)togo;
		r = (double)rem;

		real = (tg*tg - tg + 2.0*(r)) / (2.0*tg);

		/*
		a = (t - 1.0);
		b = -(t*(t - 1.0) - 2.0);
		c = (t - 1.0)*(t - 1.0) - 2.0*r;
		
		real = -b + sqrt(b*b - 4.0*a*c);

		real /= 2.0*a;
		*/

		cand = (long long)real;
		
		if (((cand - 1) + (cand - (togo - 1)))*(togo - 1) / 2 < rem - cand)
		{
			cand++;
		}
		
/*
		if (min > cand)
		{
			cand = min;
		}
*/
		sol.push_back(cand);

		//rec(sol, rem - cand, togo - 1);

		return cand;
	}
}

int main()
{
	int t, z;
	long long n, k;
	int i;
	vector<long long> arr;
	long long sol;
	long long ret;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%lld %lld", &n, &k);

		if (n < k*(k + 1) / 2)
		{
			printf("-1\n");

			continue;
		}

		while (k > 0)
		{
			ret = rec(arr, n, k);

			n -= ret;
			k--;
		}

		sol = (arr[0] * arr[0] - arr[0]) % 1000000007;

		for (i = 1; i < arr.size(); i++)
		{
			sol = (sol * ((arr[i] * arr[i] - arr[i]) % 1000000007)) % 1000000007;
		}

		printf("%lld\n", sol);

		arr.clear();
	}

	return 0;
}