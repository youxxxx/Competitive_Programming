#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool func(long long &a, long long &b)
{
	return a > b;
}

int main()
{
	long long n, m;
	long long i;
	vector<long long> arr;
	vector<long long> acc;
	long long input;
	long long sum = 0;

	scanf("%I64d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);

		sum += input;
	}

	sort(arr.begin(), arr.end(), func);

	scanf("%I64d", &m);

	for (i = 0; i < m; i++)
	{
		scanf("%I64d", &input);

		printf("%I64d\n", sum - arr[input - 1]);
	}

	return 0;
}