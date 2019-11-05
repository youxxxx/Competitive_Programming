#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases, tc;
	long long arr[3];
	int n;
	int i, j;
	long long sum = 0;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		sum = 0;

		for (i = 0; i < 3; i++)
		{
			scanf("%lld", &arr[i]);

			sum += arr[i];
		}

		sort(&arr[0], &arr[3]);

		printf("%lld\n", sum / 2);
	}

	return 0;
}