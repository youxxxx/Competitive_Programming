#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
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
		int n, m;

		scanf("%d %d", &n, &m);

		bool valid = true;

		int cur = 0;
		int lb, ub;

		lb = ub = m;

		for (int i = 0; i < n; i++)
		{
			int t, l, h;

			scanf("%d %d %d", &t, &l, &h);

			if (!valid)
			{
				continue;
			}

			lb -= (t - cur);
			ub += (t - cur);
			cur = t;

			if (l > lb)
			{
				lb = l;
			}

			if (h < ub)
			{
				ub = h;
			}

			if (lb > ub)
			{
				valid = false;
			}
		}

		if (valid)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}