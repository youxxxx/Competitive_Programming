#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

int main()
{
	long long n, k;
	vector<long long> arr;

	scanf("%lld %lld", &n, &k);

	for (long long i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end(), greater<long long>());

	long long sum = 0;

	for (long long i = k; i < n; i++)
	{
		sum += arr[i];
	}

	printf("%lld\n", sum);

	return 0;
}