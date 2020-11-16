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

	int n, m;

	scanf("%d", &n);

	int cnt[100001] = { 0, };

	int sq = 0, rec = 0;

	for (int i = 0; i < n; i++)
	{
		int val;

		scanf("%d", &val);

		cnt[val]++;

		switch (cnt[val])
		{
		case 2:
			rec++;
			break;
		case 4:
			rec--;
			sq++;
			break;
		case 6:
			rec++;
			break;
		case 8:
			rec--;
			sq++;
			break;
		}
	}

	scanf("%d", &m);

	char dummy;

	scanf("%c", &dummy);

	for (int i = 0; i < m; i++)
	{
		char op;

		scanf("%c", &op);

		if (op == '+')
		{
			int val;

			scanf("%d", &val);

			cnt[val]++;

			switch (cnt[val])
			{
			case 2:
				rec++;
				break;
			case 4:
				rec--;
				sq++;
				break;
			case 6:
				rec++;
				break;
			case 8:
				rec--;
				sq++;
				break;
			}
		}

		else
		{
			int val;

			scanf("%d", &val);

			switch (cnt[val])
			{
			case 2:
				rec--;
				break;
			case 4:
				rec++;
				sq--;
				break;
			case 6:
				rec--;
				break;
			case 8:
				rec++;
				sq--;
				break;
			}

			cnt[val]--;
		}

		if (sq >= 2 || sq == 1 && rec >= 2)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}

		scanf("%c", &dummy);
	}

	return 0;
}