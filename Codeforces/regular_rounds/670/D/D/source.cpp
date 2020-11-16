#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, m;

	scanf("%d", &n);

	long long arr[100001];

	arr[0] = 0;
	long long prev = 0;

	for (int i = 1; i <= n; i++)
	{
		long long input;

		scanf("%lld", &input);

		arr[i] = input - prev;

		prev = input;
	}

	long long val = arr[1];

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] > 0)
		{
			val += arr[i];
		}
	}

	long long sol = val / 2;
	if (val > 0)
	{
		sol = (val + 1) / 2;
	}

	printf("%lld\n", sol);

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int l, r;
		long long x;

		scanf("%d %d %lld", &l, &r, &x);

		if (l == 1)
		{
			val += x;
			arr[1] += x;
		}

		else
		{
			if (arr[l] + x > 0)
			{
				val += arr[l] + x;
			}

			if (arr[l] > 0)
			{
				val -= arr[l];
			}

			arr[l] += x;
		}

		if (r != n)
		{
			r++;

			if (arr[r] - x > 0)
			{
				val += arr[r] - x;
			}

			if (arr[r] > 0)
			{
				val -= arr[r];
			}

			arr[r] -= x;
		}

		long long sol = val / 2;

		if (val > 0)
		{
			sol = (val + 1) / 2;
		}

		printf("%lld\n", sol);
	}

	return 0;
}