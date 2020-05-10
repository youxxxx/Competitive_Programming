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
		int n, k;

		scanf("%d %d", &n, &k);

		string str;
		char input[200001];

		scanf("%s", input);
		str = input;

		int cnt[200001][26];

		for (int i = 0; i < (k + 1) / 2; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				cnt[i][j] = 0; 
			}
		}

		for (int i = 0; i < n / k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				int idx;

				idx = j < k - j - 1 ? j : k - j - 1;

				cnt[idx][str[i*k + j] - 'a']++;
			}
		}

		int sol = 0;

		for (int i = 0; i < (k + 1) / 2; i++)
		{
			int lmax = 0;

			for (int j = 0; j < 26; j++)
			{
				if (cnt[i][j] > lmax)
				{
					lmax = cnt[i][j];
				}
			}

			int add;

			if (i == k / 2)
			{
				add = n / k;
			}

			else
			{
				add = n / k * 2;
			}

			add -= lmax;

			sol += add;
		}

		printf("%d\n", sol);
	}

	return 0;
}