#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

vector<long long> arr;
long long k;
int n;

long long bin_search(long long lb, long long ub)
{
	long long next;
	long long val = 0;
	int i;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	for (i = n / 2; i < n; i++)
	{
		val += arr[i] < next ? next - arr[i] : 0;
	}

	if (val <= k)
	{
		return bin_search(next, ub);
	}

	return bin_search(lb, next);
}

int main()
{
	long long input;
	int i;
	long long rvalue;

	scanf("%d %lld", &n, &k);
	
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &input);

		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	rvalue = bin_search(arr[n / 2], arr[n / 2] + k + 1);

	printf("%lld\n", rvalue);

	return 0;
}