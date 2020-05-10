#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	vector<long long> acc;
	vector<long long> a, b;
	long long input;
	int n, q;
	int i;
	int l, r;

	scanf("%d %d", &n, &q);

	acc.push_back(0);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		a.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		b.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		acc.push_back(acc[i] + a[i] * b[i]);
	}

	for (i = 0; i < q; i++)
	{
		scanf("%d %d", &l, &r);

		printf("%lld\n", acc[r] - acc[l - 1]);
	}

	return 0;
}