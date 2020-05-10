#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long cases;

	//freopen("input.txt", "r", stdin);

	scanf("%lld", &cases);

	for (long long tc = 0; tc < cases; tc++)
	{
		long long n;
		long long prev;
		vector<long long> arr;

		scanf("%lld", &n);

		scanf("%lld", &prev);
		long long cnt = 1;

		for (long long i = 1; i < n; i++)
		{
			long long input;

			scanf("%lld", &input);

			if (input != prev)
			{
				arr.push_back(cnt);

				cnt = 1;

				prev = input;
			}

			else
			{
				cnt++;
			}
		}

		arr.push_back(cnt);

		long long sum = 0;
		long long idx;

		idx = arr.size();

		for (long long i = 0; i < arr.size(); i++)
		{
			if (sum + arr[i] > n / 2)
			{
				idx = i;

				break;
			}

			sum += arr[i];
		}

		if (idx < 3)
		{
			printf("0 0 0\n");

			continue;
		}

		long long sum2 = 0;

		long long idx2 = idx;

		for (long long i = 1; i < idx; i++)
		{
			sum2 += arr[i];

			if (sum2 > arr[0])
			{
				idx2 = i;

				break;
			}
		}

		if (idx2 >= idx - 1 || (sum - arr[0] - sum2) <= arr[0])
		{
			printf("0 0 0\n");

			continue;
		}

		printf("%lld %lld %lld\n", arr[0], sum2, (sum - arr[0] - sum2));
	}

	return 0;
}