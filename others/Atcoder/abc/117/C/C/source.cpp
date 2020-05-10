#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long n, m;
	vector<long long> arr;
	vector<long long> diff;
	long long input;
	long long i;
	long long sum = 0;

	scanf("%lld %lld", &n, &m);

	for (i = 0; i < m; i++)
	{
		scanf("%lld", &input);
		
		arr.push_back(input);
	}

	if (n >= m)
	{
		printf("0\n");

		return 0;
	}

	sort(arr.begin(), arr.end());

	for (i = 0; i < m - 1; i++)
	{
		diff.push_back(arr[i + 1] - arr[i]);
	}

	sort(diff.begin(), diff.end());

	for (i = 0; i < m - n; i++)
	{
		sum += diff[i];
	}

	printf("%lld\n", sum);

	return 0;
}