#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

int main()
{
	long long n;
	long long sum;
	vector<long long> arr, sol;
	long long input;
	long long i;

	scanf("%lld", &n);

	sum = n*(n + 1) / 2;

	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);

	}

	return 0;
}