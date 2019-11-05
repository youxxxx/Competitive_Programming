#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
	int t, z;
	long long n, k;
	long long i;
	vector<long long> arr;
	long long input;
	long long lmin, coord;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		arr.clear();

		scanf("%lld %lld", &n, &k);

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			arr.push_back(input);
		}

		if (n == 1 || k == 0)
		{
			printf("%lld\n", arr[0]);

			continue;
		}
		
		lmin = 9999999999;

		for (i = 0; i < n - k; i++)
		{
			if (arr[i + k] - arr[i] < lmin)
			{
				lmin = arr[i + k] - arr[i];

				coord = (arr[i] + arr[i + k]) / 2;
			}
		}

		printf("%lld\n", coord);
	}

	return 0;
}