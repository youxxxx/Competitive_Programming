#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
	int i, j;
	int n, k;
	vector<long long> arr, psum;
	long long cur = 0, tot = 0, sol = 0;
	long long input;
	
	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);

		tot += input;
	}

	for (i = n - 1; i >= 1; i--)
	{
		cur += arr[i];

		psum.push_back(cur);
	}

	sort(psum.begin(), psum.end());

	for (i = 0; i < k - 1; i++)
	{
		sol += psum[n - 2 - i];
	}

	printf("%lld\n", sol + tot);

	return 0;
}