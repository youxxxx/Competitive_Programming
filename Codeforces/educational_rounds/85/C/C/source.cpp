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
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		vector<long long> a, b;

		for (int i = 0; i < n; i++)
		{
			long long input1, input2;

			scanf("%lld %lld", &input1, &input2);

			a.push_back(input1);
			b.push_back(input2);
		}

		for (int i = 0; i < n; i++)
		{
			if (a[(i + 1) % n] < b[i])
			{
				b[i] = a[(i + 1) % n];
			}
		}

		long long lmin = 999999999999999999;
		int lidx = 0;

		for (int i = 0; i < n; i++)
		{
			if (b[i] < lmin)
			{
				lmin = b[i];

				lidx = i;
			}
		}

		long long sol = 0;

		for (int i = 0; i < n; i++)
		{
			int cur, next;

			cur = (i + lidx + 1) % n;
			next = (i + lidx + 2) % n;

			sol += a[cur];
			a[next] -= b[cur];
		}

		printf("%lld\n", sol);
	}

	return 0;
}