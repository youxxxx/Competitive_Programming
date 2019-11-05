#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	long long n, t;
	long long s, d;
	long long sol;
	long long cand;
	long long lmax = 99999999;
	long long i;

	scanf("%I64d %I64d", &n, &t);
	
	for (i = 0; i < n; i++)
	{
		scanf("%I64d %I64d", &s, &d);

		if (t == s)
		{
			cand = s;
		}

		else if (t > s)
		{
			if (!((t - s) % d))
			{
				cand = t;
			}

			else
			{
				cand = t + d;
			}
		}

		else
		{
			cand = s;
		}

		if (cand < lmax)
		{
			sol = i + 1;
			lmax = cand;
		}
	}

	printf("%I64d\n", sol);

	return 0;
}