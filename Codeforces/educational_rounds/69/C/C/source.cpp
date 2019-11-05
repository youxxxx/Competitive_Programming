#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

#define MOD 998244353

using namespace std;

int main()
{
	vector<long long> diff;
	int n, k;
	int i;
	long long input, prev, start, sum;

	scanf("%d %d", &n, &k);

	scanf("%lld", &input);

	start = prev = input;

	for (i = 0; i < n - 1; i++)
	{
		scanf("%lld", &input);

		diff.push_back(input - prev);

		prev = input;
	}

	sum = prev - start;

	sort(diff.begin(), diff.end(), greater<long long>());

	for (i = 0; i < k - 1; i++)
	{
		sum -= diff[i];
	}

	printf("%lld\n", sum);

	return 0;
}