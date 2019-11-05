#include<cstdio>
#include<vector>

using namespace std;

long long gcd(long long a, long long b)
{
	long long temp;

	while (b != 0)
	{
		a %= b;

		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	long long *dp;
	long long input;
	long long div;
	int n;
	int i, j;
	vector<long long> arr;

	scanf("%d", &n);

	dp = new long long[n];

	scanf("%I64d", &input);

	arr.push_back(input);

	div = input;

	for (i = 1; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);

		div = gcd(div, input);
	}


}