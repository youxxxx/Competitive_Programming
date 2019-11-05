#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n, k, m;
	long long i;
	vector<long long> arr;
	long long input;
	long long sol;
	long long q, r;

	scanf("%I64d %I64d %I64d", &n, &m, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	q = m / (k + 1);
	r = m % (k + 1);

	sol = (arr[n - 1] * (k)+arr[n - 2])*q + (arr[n - 1] * r);

	printf("%I64d\n", sol);

	return 0;
}