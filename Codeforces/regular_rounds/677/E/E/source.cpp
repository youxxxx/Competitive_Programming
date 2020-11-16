#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	long long perm[21];

	perm[0] = perm[1] = 1;

	for (long long i = 2; i <= 20; i++)
	{
		perm[i] = perm[i - 1] * i;
	}

	long long n;

	scanf("%lld", &n);

	const long long base = perm[n] / perm[n / 2] / perm[n / 2] / 2;

	long long num = perm[n / 2] / (n/2);

	/*
	if (num != 1)
	{
		num /= 2;
	}
	*/

	const long long sol = base*num*num;

	printf("%lld\n", sol);

	return 0;
}