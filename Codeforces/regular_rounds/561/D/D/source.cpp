#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long a, b, m;
	int i, j;
	int t, z;
	int n;
	long long lmin, lmax, target, cur, lim, curmin;
	bool valid;
	long long q, r, acc;
	vector<long long> arr, sol;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%I64d %I64d %I64d", &a, &b, &m);

		if (a == b)
		{
			printf("1 %I64d\n", a);

			continue;
		}

		if (b < a * 2)
		{
			if (b - a <= m)
			{
				printf("2 %I64d %I64d\n", a, b);
			}

			else
			{
				printf("-1\n");
			}

			continue;
		}

		valid = false;

		for (i = 2; i <= 52; i++)
		{
			lmin = (long long)pow(2.0, i - 1)*(a + 1);

			if (lmin > b)
			{
				break;
			}

			lmax = (long long)pow(2.0, i - 1)*(a + m);

			if (lmax < b)
			{
				continue;
			}

			target = b - lmin;

			r = target;

			cur = pow(2.0, i - 2);

			lim = (long long)pow(2.0, i - 1)*(m - 1);

			//curmin = (long long)pow(2.0, i - 2);

			arr.clear();

			for (j = 0; j < i - 1; j++)
			{
				q = r / cur < m - 1 ? r / cur : m - 1;

				/*
				if (r - q*cur < curmin)
				{
					q--;
				}
				*/

				arr.push_back(q + 1);

				r -= q*cur;
				//curmin /= 2;
				cur /= 2;
			}

			sol.clear();

			if (r <= m - 1)
			{
				valid = true;

				arr.push_back(r + 1);

				printf("%d %lld", i + 1, a);
				//sol.push_back(a);
				
				acc = a;

				for (j = 0; j < i; j++)
				{
					//sol.push_back(acc + arr[j]);

					printf(" %lld", acc + arr[j]);
					acc += acc + arr[j];
				}

				printf("\n");

				break;
			}
		}

		if (!valid)
		{
			printf("-1\n");
		}
	}

	return 0;
}