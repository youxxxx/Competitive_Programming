#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	int dx[256] = { 0, };
	int dy[256] = { 0, };

	dy['N'] = 1;
	dy['S'] = -1;
	dx['E'] = 1;
	dx['W'] = -1;

	for (int tc = 1; tc <= cases; tc++)
	{
		int x, y;

		scanf("%d %d", &x, &y);

		char input[1001];
		string str;

		scanf("%s", input);

		str = input;

		const int n = str.size();

		int sol = 0;
		
		for (int i = 0; i < n; i++)
		{
			x += dx[str[i]];
			y += dy[str[i]];

			int ax, ay;

			ax = abs(x);
			ay = abs(y);

			if (ax + ay <= (i + 1))
			{
				sol = i + 1;

				break;
			}
		}

		if (sol == 0)
		{
			printf("Case #%d: IMPOSSIBLE\n", tc);
		}

		else
		{
			printf("Case #%d: %d\n", tc, sol);
		}
	}

	return 0;
}