#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	long long n, x;
	long long i, j;
	vector<long long> arr;
	long long input;
	long long *cnt, *fac;

	cnt = new long long[100000];
	fac = new long long[100000];
	mp = new map<long long, long long>[100000];

	scanf("%lld %lld", &n, &x);

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);
	}

	cnt[0] = 0;
	fac[0] = 1;

	for (i = 1; i < 100000; i++)
	{
		cnt[i] = 0;

		fac[i] = (fac[i - 1] * i) % 1000000007;
	}

	sort(arr.begin(), arr.end());

	return 0;
}