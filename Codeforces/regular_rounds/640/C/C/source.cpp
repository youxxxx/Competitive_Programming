#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, k;

		scanf("%d %d", &n, &k);

		int q, r;

		q = k / (n - 1);
		r = k % (n - 1);

		printf("%d\n", q*n + r - !r);
	}

	return 0;
}