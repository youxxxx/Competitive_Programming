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
		long long bx[4], by[4];

		for (long long i = 0; i < 4; i++)
		{
			scanf("%lld %lld", &bx[i], &by[i]);
		}

		int p[4] = { 0,1,2,3 };
		long long sol = 9999999999;

		do
		{
			long long x[4], y[4];

			for (int i = 0; i < 4; i++)
			{
				x[i] = bx[p[i]];
				y[i] = by[p[i]];
			}

			long long cand = 0;

			{
				long long lmax = max(x[0], x[1]);
				long long rmin = min(x[2], x[3]);

				long long inv[4] = { 0, };

				inv[0] = max(0ll, x[0] - (rmin - 1));
				inv[1] = max(0ll, x[1] - (rmin - 1));
				inv[2] = max(0ll, (lmax + 1) - x[2]);
				inv[3] = max(0ll, (lmax + 1) - x[3]);

				if (inv[0] + inv[1] < inv[2] + inv[3])
				{
					cand += inv[0] + inv[1];

					x[0] = min(x[0], rmin - 1);
					x[1] = min(x[1], rmin - 1);
				}

				else
				{
					cand += inv[2] + inv[3];

					x[2] = max(x[2], lmax + 1);
					x[3] = max(x[3], lmax + 1);
				}
			}

			{
				long long lmax = max(y[0], y[2]);
				long long rmin = min(y[1], y[3]);

				long long inv[4] = { 0, };

				inv[0] = max(0ll, y[0] - (rmin - 1));
				inv[2] = max(0ll, y[2] - (rmin - 1));
				inv[1] = max(0ll, (lmax + 1) - y[1]);
				inv[3] = max(0ll, (lmax + 1) - y[3]);

				if (inv[0] + inv[2] < inv[1] + inv[3])
				{
					cand += inv[0] + inv[2];

					y[0] = min(y[0], rmin - 1);
					y[2] = min(y[2], rmin - 1);
				}

				else
				{
					cand += inv[1] + inv[3];

					y[1] = max(y[1], lmax + 1);
					y[3] = max(y[3], lmax + 1);
				}
			}

			cand += abs(x[1] - x[0]) + abs(x[3] - x[2]) + abs(y[2] - y[0]) + abs(y[3] - y[1]);
	
			const long long xmin = min(x[2], x[3]) - max(x[0], x[1]);
			const long long xmax = max(x[2], x[3]) - min(x[0], x[1]);
			const long long ymin = min(y[1], y[3]) - max(y[0], y[2]);
			const long long ymax = max(y[1], y[3]) - min(y[0], y[2]);

			if (xmax < ymin)
			{
				cand += (ymin - xmax) * 2;
			}

			else if (ymax < xmin)
			{
				cand += (xmin - ymax) * 2;
			}

			if (cand < sol)
			{
				sol = cand;
			}
		} while (next_permutation(p, p + 4));

		printf("%lld\n", sol);
	}

	return 0;
}