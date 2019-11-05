#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int n, v;
	int i;
	int q, r;
	int sol;

	scanf("%d %d", &n, &v);

	if (v >= n - 1)
	{
		printf("%d\n", n - 1);

		return 0;
	}

	q = (n - 1) / v;
	r = (n - 1) % v;

	sol = v + (2 + (n - v))*(n - v - 1) / 2;

	printf("%d\n", sol);

	return 0;
}