#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n, m, ta, tb, k;
	vector<long long> a, b;
	long long i;
	long long input;
	long long ptr = 0;
	long long lmax = -1;

	scanf("%lld %lld %lld %lld %lld", &n, &m, &ta, &tb, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		a.push_back(input + ta);
	}

	for (i = 0; i < m; i++)
	{
		scanf("%lld", &input);

		b.push_back(input);
	}

	if (k >= n || k >= m)
	{
		printf("-1\n");

		return 0;
	}

	for (i = 0; i < n&&i <= k; i++)
	{
		while (ptr < m&&b[ptr] < a[i])
		{
			ptr++;
		}

		if (ptr + (k - i) >= m)
		{
			printf("-1\n");

			return 0;
		}

		if (b[ptr + (k - i)] > lmax)
		{
			lmax = b[ptr + (k - i)];
		}
	}

	printf("%lld\n", lmax + tb);

	return 0;
}
