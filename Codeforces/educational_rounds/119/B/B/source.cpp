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

void io()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
}

int main()
{
	io();

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++) {
		long long n, m;

		scanf("%lld %lld", &n, &m);

		long long val[4][2];

		for (int i = 0; i < 4; i++) {
			int k;

			scanf("%d", &k);

			scanf("%lld", &val[i][0]);

			for (int j = 0; j < k - 2; j++) {
				long long input;

				scanf("%lld", &input);
			}

			scanf("%lld", &val[i][1]);
		}

		long long lmax = 0;

		for (int i = 0; i < 2; i++) {
			lmax = max(lmax, (val[i][1] - val[i][0])*m);
			lmax = max(lmax, (val[i+2][1] - val[i+2][0])*n);
		}

		printf("%lld\n", lmax);
	}

	return 0;
}