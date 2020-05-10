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

		int p = 0, c = 0;
		
		bool valid = true;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int np, nc;

			scanf("%d %d", &np, &nc);

			if (np < p || nc < c || np - p < nc - c)
			{
				valid = false;
			}

			p = np;
			c = nc;
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