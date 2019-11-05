#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool func(long long &a, long long &b)
{
	return a > b;
}

int main()
{
	long long n, m, k;
	vector<long long> arr, interv;
	long long input;
	long long i;
	long long sum = 0;

	scanf("%I64d %I64d %I64d", &n, &m, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);
	}

	for (i = 0; i < n - 1; i++)
	{
		interv.push_back(arr[i + 1] - arr[i] - 1);
	}

	sum = arr[n - 1] - arr[0] + 1;

	sort(interv.begin(), interv.end(), func);

	for (i = 0; i < k - 1; i++)
	{
		sum -= interv[i];
	}

	printf("%I64d\n", sum);

	return 0;
}