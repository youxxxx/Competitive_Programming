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
	int n;
	unsigned long long sol[501][501] = { 0, };
	unsigned long long s[501], t[501], r[501], c[501];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%llu", &s[i]);
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%llu", &t[i]);
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%llu", &r[i]);
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%llu", &c[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 0)
		{
			for (int j = 0; j < n; j++)
			{
				sol[i][j] |= r[i];
			}
		}

		if (t[i] == 0)
		{
			for (int j = 0; j < n; j++)
			{
				sol[j][i] |= c[i];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 1)
		{
			bool found = false;

			for (int j = 0; j < n; j++)
			{
				if (c[j] & r[i] == r[i])
				{
					sol[i][j] |= r[i];

					found = true;

					break;
				}
				if (t[j] == 1)
				{
				}
				
				else
				{
					if()
				}
			}

			if (!found)
			{
				printf("-1\n");

				return 0;
			}
		}

		if (t[i] == 1)
		{
			bool found = false;

			for (int j = 0; j < n; j++)
			{
				if (t[j] == 1 || sol[j][i] & c[i] == c[i])
				{
					sol[j][i] |= r[i];

					found = true;

					break;
				}
			}

			if (!found)
			{
				printf("-1\n");

				return 0;
			}
		}
	}

	return 0;
}