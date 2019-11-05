#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, q;
	vector<long long> arr, sol;
	long long input;
	long long res;
	int i;
	long long target;

	scanf("%d %d", &n, &q);

	res = 0;

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		res ^= input;

		sol.push_back(res);

		arr.push_back(input);
	}

	sol.push_back(0);

	for (i = 0; i < q; i++)
	{
		scanf("%lld", &target);

		printf("%lld\n", sol[(target - 1) % (n + 1)]);
	}

	return 0;
}