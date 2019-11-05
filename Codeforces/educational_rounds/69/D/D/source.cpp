#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

#define MOD 998244353

using namespace std;

int main()
{
	vector<long long> arr, cur, psum;
	int n, m;
	int i, j;
	long long sub;
	long long input;
	long long lmax[2][11] = { 0, };
	long long prev[11] = { 0, };
	long long sol = 0;
	long long temp;
	int target, q;

	scanf("%d %d %lld", &n, &m, &sub);

	arr.push_back(0);
	psum.push_back(0);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);

		psum.push_back(psum.back() + input);
	}

	if (m == 1)
	{
		for (i = 1; i <= n; i++)
		{
			lmax[0][0] += arr[i] - sub;

			if (lmax[0][0] < 0)
			{
				lmax[0][0] = 0;
			}

			if (lmax[0][0] > sol)
			{
				sol = lmax[0][0];
			}
		}

		printf("%lld\n", sol);

		return 0;
	}

	if (n <= m)
	{
		lmax[0][0] = 0;

		for (i = 1; i <= n; i++)
		{
			lmax[0][0] += arr[i];

			if (lmax[0][0] < 0)
			{
				lmax[0][0] = 0;
			}

			if (lmax[0][0] - sub > sol)
			{
				sol = lmax[0][0] - sub;
			}
		}

		printf("%lld\n", sol);

		return 0;
	}

	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= i; j++)
		{
			lmax[i%2][j] = lmax[!(i % 2)][(j + m - 1) % m] + arr[i];

			if (lmax[i % 2][j] - sub > sol)
			{
				sol = lmax[i % 2][j] - sub;
			}
		}
	}

	lmax[m % 2][0] = lmax[m % 2][m];

	for (i = 0; i < m; i++)
	{
		lmax[m % 2][i] -= sub;

		prev[i] = (m - i) % m;
	}

	for (i = m + 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			lmax[i % 2][j] = lmax[!(i % 2)][j - 1] + arr[i];
		}

		lmax[i % 2][0] = lmax[i % 2][m];

		lmax[i % 2][1] -= sub;

		temp = prev[m - 1];

		for (j = m - 1; j >= 1; j--)
		{
			prev[j] = prev[j - 1];
		}

		prev[0] = temp;

		for (j = 0; j < m; j++)
		{
			q = (i- prev[j]) / m*m;

			target = prev[j] + q;
			if (q &&psum[target] - psum[prev[j]] - sub*q/m <= 0)
			{
				lmax[i % 2][j] -= psum[target] - psum[prev[j]] - sub*q / m;

				prev[j] = target;
			}

			if (lmax[i%2][j] > sol)
			{
				sol = lmax[i%2][j];
			}
		}
	}

	printf("%lld\n", sol);

	return 0;
}