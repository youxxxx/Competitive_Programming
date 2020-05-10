#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
	int n, k;
	vector<int> arr(200000);
	long long val = 0;
	long long lmax;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < k; i++)
	{
		scanf("%lld", &arr[i]);

		val += arr[i] + 1;
	}

	lmax = val;

	for (int i = k; i < n; i++)
	{
		scanf("%lld", &arr[i]);

		val += arr[i] + 1;

		val -= arr[i - k] + 1;

		if (val > lmax)
		{
			lmax = val;
		}
	}

	printf("%.8lf\n", (double)lmax / (double)2);

	return 0;
}