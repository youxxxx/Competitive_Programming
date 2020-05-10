#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, k1, k2;

		scanf("%d %d %d", &n, &k1, &k2);

		bool win = false;

		for (int i = 0; i < k1; i++)
		{
			int input;

			scanf("%d", &input);

			if (input == n)
			{
				win = true;
			}
		}

		for (int i = 0; i < k2; i++)
		{
			int input;

			scanf("%d", &input);
		}

		if (win)
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
