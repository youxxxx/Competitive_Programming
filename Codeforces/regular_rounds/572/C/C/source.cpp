#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int i;
	int n, q;
	vector<long long> arr, acc;
	long long input;
	long long temp;
	int l, r;

	scanf("%d", &n);

	acc.push_back(0);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);

		acc.push_back(acc[i] + input);
	}

	scanf("%d", &q);

	for (i = 0; i < q; i++)
	{
		scanf("%d %d", &l, &r);

		printf("%lld\n", (acc[r] - acc[l - 1]) / 10);
	}

	return 0;
}