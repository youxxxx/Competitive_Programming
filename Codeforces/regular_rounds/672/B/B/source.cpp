#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	long long cur = 1;

	long long pw[32];

	for (int i = 0; i < 32; i++)
	{
		pw[i] = cur;

		cur *= 2;
	}

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		long long cnt[32] = { 0, };

		long long sol = 0;

		for (int i = 0; i < n; i++)
		{
			long long input;

			scanf("%lld", &input);

			int level = 32;

			for (int j = 0; j < 32; j++)
			{
				if (input < pw[j])
				{
					level = j - 1;

					break;
				}
			}

			sol += cnt[level]++;
		}

		printf("%lld\n", sol);
	}

	return 0;
}