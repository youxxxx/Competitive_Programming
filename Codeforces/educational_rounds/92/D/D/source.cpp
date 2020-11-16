#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long n, k;

		long long al, ar, bl, br;

		scanf("%lld %lld", &n, &k);

		scanf("%lld %lld %lld %lld", &al, &ar, &bl, &br);

		if (al > bl)
		{
			long long temp;

			temp = al;
			al = bl;
			bl = temp;

			temp = ar;
			ar = br;
			br = temp;
		}

		const long long l = al;
		const long long r = ar > br ? ar : br;

		const long long gap = ar < bl ? bl - ar : 0;
		const long long base = (ar < br ? ar : br) > bl ? (ar < br ? ar : br) - bl : 0;

		k -= base*n;

		if (k <= 0)
		{
			printf("0\n");

			continue;
		}

		long long cost = 0;
		long long sol = 999999999999;

		for (long long i = 0; i < n; i++)
		{
			cost += gap;

			if (k <= (r - l) - base)
			{
				cost += k;

				if (cost < sol)
				{
					sol = cost;
				}

				break;
			}

			cost += (r - l) - base;
			k -= (r - l) - base;

			if (cost + k * 2 < sol)
			{
				sol = cost + k * 2;
			}
		}

		printf("%lld\n", sol);
	}

	return 0;
}