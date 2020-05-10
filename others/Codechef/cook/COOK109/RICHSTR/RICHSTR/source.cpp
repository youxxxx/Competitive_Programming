#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	int n, m;
	int i;
	int l, r;
	char input[100001];
	int psum[100001];
	int val[100001];
	int cnt[26];
	string str;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d %d", &n, &m);

		scanf("%s", input);

		str = input;

		if (n < 3)
		{
			for (i = 0; i < m; i++)
			{
				scanf("%d %d", &l, &r);

				printf("NO\n");
			}

			continue;
		}

		for (i = 0; i <= n; i++)
		{
			psum[i] = val[i] = 0;
		}

		psum[0] = 0;

		if (str[0] == str[1] || str[1] == str[2] || str[2] == str[0])
		{
			val[1] = psum[1] = 1;
		}

		else
		{
			val[1] = psum[1] = 0;
		}

		for (i = 1; i < n - 2; i++)
		{
			if (str[i] == str[i + 1] || str[i + 1] == str[i + 2] || str[i + 2] == str[i])
			{
				val[i + 1] = 1;
			}

			else
			{
				val[i + 1] = 0;
			}

			psum[i + 1] = psum[i] + val[i + 1];
		}

		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &l, &r);

			if (r - l < 2)
			{
				printf("NO\n");
			}

			else
			{
				if (psum[r - 2] - psum[l - 1])
				{
					printf("YES\n");
				}

				else
				{
					printf("NO\n");
				}
			}
		}
	}

	return 0;
}
