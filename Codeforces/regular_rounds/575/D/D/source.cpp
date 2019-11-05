#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases, tc;
	int n, k;
	int i, j;
	char ch[4] = "RGB";
	string str;
	char input[200001];
	int cnt, lmin;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d %d", &n, &k);

		scanf("%s", input);

		str = input;

		lmin = 200001;

		for (i = 0; i < 3; i++)
		{
			cnt = 0;

			for (j = 0; j < k; j++)
			{
				cnt += (ch[(i + j) % 3] != str[j]);
			}

			if (cnt < lmin)
			{
				lmin = cnt;
			}

			for (j = k; j < n; j++)
			{
				cnt -= (ch[(i + j - k) % 3] != str[j - k]);

				cnt += (ch[(i + j) % 3] != str[j]);

				if (cnt < lmin)
				{
					lmin = cnt;
				}
			}
		}

		printf("%d\n", lmin);
	}

	return 0;
}