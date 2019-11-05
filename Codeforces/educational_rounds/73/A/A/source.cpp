#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int i, j;
	int tc, cases;
	int cnt[12];
	int pw;
	int input;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d", &n);

		for (i = 0; i <= 11; i++)
		{
			cnt[i] = 0;
		}

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			pw = (int)log2(double(input));

			for (j = pw; j < 11; j++)
			{
				if (++cnt[j] < 2)
				{
					break;
				}

				cnt[j] = 0;
			}

			if (j == 11)
			{
				cnt[11]++;
			}
		}

		if (cnt[11])
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