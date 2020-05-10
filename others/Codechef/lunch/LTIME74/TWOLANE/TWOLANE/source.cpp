#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long cases, tc;
	long long i, j;
	long long n, k, d;
	long long sol;
	vector<long long> arr, lane;
	long long input;
	long long cur, space;

	//freopen("input.txt", "r", stdin);

	scanf("%lld", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%lld %lld %lld", &n, &k, &d);

		arr.clear();
		lane.clear();

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			arr.push_back(input);
		}

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			lane.push_back(input);
		}

		cur = 3 - lane[0];
		space = -d;

		for (i = 1; i < n; i++)
		{
			if (lane[i] != cur)
			{
				continue;
			}

			space = space + d > arr[i - 1] + 1 ? space + d : arr[i - 1] + 1;

			if (arr[i] <= space)
			{
				break;
			}

			cur = 3 - lane[i];
		}

		if (i == n)
		{
			printf("%lld\n", k);
		}

		else
		{
			printf("%lld\n", arr[i]);
		}
	}

	return 0;
}