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

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long x, y;

		scanf("%lld %lld", &x, &y);

		long long arr[6];

		for (int i = 0; i < 6; i++)
		{
			scanf("%lld", &arr[i]);
		}

		long long dist[6];

		for (int i = 0; i < 6; i++)
		{
			dist[i] = min(arr[i], arr[(i + 5) % 6] + arr[(i + 1) % 6]);
		}

		long long val[6] = { 0, };

		if (x > 0 && y > 0)
		{
			val[0] += min(x, y);

			x -= val[0];
			y -= val[0];
		}

		if (x < 0 && y < 0)
		{
			val[3] += -max(x, y);

			x += val[3];
			y += val[3];
		}

		if (x > 0)
		{
			val[5] += x;
		}

		if (x < 0)
		{
			val[2] += -x;
		}

		if (y > 0)
		{
			val[1] += y;
		}

		if (y < 0)
		{
			val[4] += -y;
		}

		long long sol = 0;

		for (int i = 0; i < 6; i++)
		{
			sol += val[i] * dist[i];
		}

		printf("%lld\n", sol);
	}

	return 0;
}