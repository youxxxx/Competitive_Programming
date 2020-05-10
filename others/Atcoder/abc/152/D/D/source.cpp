#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	long long cnt[10][10] = { 0, };

	for (int i = 1; i <= n; i++)
	{
		int first, last;
		int temp;

		temp = i;

		last = temp % 10;

		while (temp / 10)
		{
			temp /= 10;
		}

		first = temp;

		cnt[first][last]++;
	}

	long long sol = 0;

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			sol += cnt[i][j] * cnt[j][i];
		}
	}

	printf("%lld\n", sol);

	return 0;
}