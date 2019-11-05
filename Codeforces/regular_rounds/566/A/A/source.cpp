#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

#define MOD 1000000007;

using namespace std;

int main()
{
	int n;
	int sol = 0;

	scanf("%d", &n);

	if (!(n % 2))
	{
		sol = (int)pow(2.0, n / 2);
	}

	printf("%d\n", sol);

	return 0;
}