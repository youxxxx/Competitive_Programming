#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int cnt[1001] = { 0, };
	int n, m;
	int input;
	int i;
	int sol = 0, half = 0, tot;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		cnt[input]++;
	}

	tot = n + n % 2;

	for (i = 1; i <= m; i++)
	{
		sol += cnt[i] - cnt[i] % 2;

		half += cnt[i] % 2;
	}

	sol += (tot - sol + 1) / 2;

	printf("%d\n", sol);

	return 0;
}