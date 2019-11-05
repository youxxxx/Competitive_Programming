#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int n;
	vector<long long> arr;
	long long input;
	int i;
	long long sum = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);

		sum += input;
	}

	if (sum % 2)
	{
		printf("NO\n");

		return 0;
	}

	sort(arr.begin(), arr.end());

	if (arr.back() > sum - arr.back())
	{
		printf("NO\n");

		return 0;
	}

	printf("YES\n");

	return 0;
}