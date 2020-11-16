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
		int a[3], b[3];

		for (int i = 0; i < 3; i++)
		{
			scanf("%d", &a[i]);
		}

		for (int i = 0; i < 3; i++)
		{
			scanf("%d", &b[i]);
		}

		int sol = 0;

		int lmin = a[2] < b[1] ? a[2] : b[1];
		a[2] -= lmin;
		b[1] -= lmin;

		sol += lmin * 2;

		lmin = a[0] < b[2] ? a[0] : b[2];
		a[0] -= lmin;
		b[2] -= lmin;

		lmin = a[1] < b[1] ? a[1] : b[1];
		a[1] -= lmin;
		b[1] -= lmin;

		lmin = a[1] < b[0] ? a[1] : b[0];
		a[1] -= lmin;
		b[0] -= lmin;

		lmin = a[1] < b[2] ? a[1] : b[2];
		a[1] -= lmin;
		b[2] -= lmin;

		sol -= lmin * 2;

		printf("%d\n", sol);
	}

	return 0;
}