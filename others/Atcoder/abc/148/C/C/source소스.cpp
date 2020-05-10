#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

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
	long long a, b;

	scanf("%lld %lld", &a, &b);

	printf("%lld\n", a*b / gcd(a, b));

	return 0;
}