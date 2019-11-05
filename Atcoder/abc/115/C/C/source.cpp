#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, k, i;
	long long input;
	vector<long long> arr;
	long long min = 1000000001;

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	for (i = 0; i < n - k + 1; i++)
	{
		if (min > arr[i + k - 1] - arr[i])
		{
			min = arr[i + k - 1] - arr[i];
		}
	}

	printf("%lld\n", min);

	return 0;
}