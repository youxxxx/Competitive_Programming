#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, x, a, b;

		scanf("%d %d %d %d", &n, &x, &a, &b);

		int sol;

		sol = n - 1 <  abs(b - a) + x ? n - 1 : abs(b - a) + x;

		printf("%d\n", sol);
	}

	return 0;
}