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
	int cases;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		int a[100001];
		int b[100001];

		int cnt[3] = { 0, };

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);

			cnt[a[i] + 1]++;
		}

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &b[i]);
		}

		bool valid = true;

		for (int i = n - 1; i >= 0; i--)
		{
			cnt[a[i] + 1]--;

			if (a[i] == b[i])
			{
				continue;
			}

			if (a[i] < b[i])
			{
				if(!cnt[2])
				{
					valid = false;

					break;
				}
			}

			else
			{
				if (!cnt[0])
				{
					valid = false;

					break;
				}
			}
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