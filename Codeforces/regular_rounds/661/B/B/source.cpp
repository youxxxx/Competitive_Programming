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
		int n;

		int a[51], b[51];

		scanf("%d", &n);

		int amin = 1000000001;
		int bmin = 1000000001;

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);

			if (a[i] < amin)
			{
				amin = a[i];
			}
		}

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &b[i]);

			if (b[i] < bmin)
			{
				bmin = b[i];
			}
		}

		long long sol = 0;

		for (int i = 0; i < n; i++)
		{
			sol += (a[i] - amin) > (b[i] - bmin) ? (a[i] - amin) : (b[i] - bmin);
		}

		printf("%lld\n", sol);
	}

	return 0;
}