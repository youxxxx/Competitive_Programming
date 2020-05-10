#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, d;

		scanf("%d %d", &n, &d);

		if (d <= n)
		{
			printf("YES\n");

			continue;
		}

		int lb;

		lb = (int)sqrt(d);
		int div;

		div = (d + lb - 1) / lb;

		bool valid = false;

		while (div >= lb)
		{
			if (lb + div - 1 <= n)
			{
				valid = true;

				break;
			}

			lb++;
			div = (d + lb - 1) / lb;
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