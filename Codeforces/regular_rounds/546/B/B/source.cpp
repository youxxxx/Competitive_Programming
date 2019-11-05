#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n, k;
	int sol;
	int lmin;

	scanf("%d %d", &n, &k);

	lmin = (k-1) < n - k ? k - 1 : n - k;

	sol = n * 3 + lmin;

	printf("%d\n", sol);

	return 0;
}