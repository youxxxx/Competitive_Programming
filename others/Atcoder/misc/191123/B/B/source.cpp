#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
	int n;
	vector<long long> arr;

	scanf("%d", &n);

	long long acc = 0;
	long long lmin = 999999999999999999;

	for (int i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		acc += input;

		arr.push_back(acc);
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (abs(arr[i] - (arr[n - 1] - arr[i])) < lmin)
		{
			lmin = abs(arr[i] - (arr[n - 1] - arr[i]));
		}
	}

	printf("%lld\n", lmin);

	return 0;
}
