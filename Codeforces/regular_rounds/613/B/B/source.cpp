#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		vector<long long> arr;
		long long acc = 0;
		long long lmin = 0, lmax = -99999999999999999;
		int n;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			long long input;

			scanf("%lld", &input);

			acc += input;

			if (acc - lmin > lmax && (lmin != 0 || i < n - 1))
			{
				lmax = acc - lmin;
			}

			if (acc < lmin)
			{
				lmin = acc;
			}

			arr.push_back(input);
		}

		if (acc <= lmax)
		{
			printf("NO\n");

			continue;
		}

		acc = 0;
		lmin = 0;
		lmax = -99999999999999999;

		for (int i = n - 1; i >= 0; i--)
		{
			acc += arr[i];

			if (acc - lmin > lmax && (lmin != 0 || i > 0))
			{
				lmax = acc - lmin;
			}

			if (acc < lmin)
			{
				lmin = acc;
			}

			arr.push_back(arr[i]);
		}

		if (acc <= lmax)
		{
			printf("NO\n");

			continue;
		}

		printf("YES\n");
	}

	return 0;
}