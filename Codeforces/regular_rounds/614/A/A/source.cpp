#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	long long cases;

	scanf("%lld", &cases);

	for (long long tc = 0; tc < cases; tc++)
	{
		long long n, s, k;

		scanf("%lld %lld %lld", &n, &s, &k);

		vector<long long> arr;

		for (long long i = 0; i < k; i++)
		{
			long long input;

			scanf("%lld", &input);

			arr.push_back(input);
		}

		sort(arr.begin(), arr.end());

		long long prev = 0;

		long long lmin = 1000000001;

		for (long long i = 0; i < k; i++)
		{
			if (arr[i] != prev + 1)
			{
				if (s > prev&&s < arr[i])
				{
					lmin = 0;

					break;
				}

				if (abs(s - (prev + 1)) < lmin)
				{
					lmin = abs(s - (prev + 1));
				}

				if (abs(s - (arr[i] - 1)) < lmin)
				{
					lmin = abs(s - (arr[i] - 1));
				}
			}

			prev = arr[i];
		}

		if (prev != n)
		{
			if (abs(s - (prev + 1)) < lmin)
			{
				lmin = abs(s - (prev + 1));
			}

			if (prev < s)
			{
				lmin = 0;
			}
		}

		printf("%lld\n", lmin);
	}

	return 0;
}