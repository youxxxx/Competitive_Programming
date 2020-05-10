#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
	long long n, m;
	vector<long long> arr;
	long long remainder[200001] = { 0, };

	scanf("%lld %lld", &n, &m);

	for (long long i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	long long cur = 0;

	for (long long i = 0; i < n; i++)
	{
		remainder[i%m] += arr[i];

		cur += remainder[i%m];

		printf("%lld ", cur);
	}

	return 0;
}