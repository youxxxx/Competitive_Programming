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

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		char input[100001];
		long long cnt[1200001];

		scanf("%d", &n);

		for (int i = 0; i <= n * 12; i++)
		{
			cnt[i] = 0;
		}

		scanf("%s", input);

		string str = input;

		long long sol = 0;
		long long cur = 0;

		for (int i = 0; i < n; i++)
		{
			cur += str[i] - '0';

			if (cur == i + 1)
			{
				sol++;
			}

			const int idx = cur + n - i;

			sol += cnt[idx];

			cnt[idx]++;
		}

		printf("%lld\n", sol);
	}

	return 0;
}